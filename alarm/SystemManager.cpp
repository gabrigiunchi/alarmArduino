#include "SystemManager.h"
#include "EventsCode.h"

#define alarm_led_pin 13
#define state_led_pin 5
#define pir_pin 3
#define pirActivationTime 10000 // Tempo necessario al sensore pir per calibrarsi correttamente

int eventType = -1; // Codice dell'evento da gestire
int code = 0; // Codice ricevuto dalla seriale
String serialMessage = "";
long programStarted; // Tempo in cui il software è partito. Serve per interrompere la calibrazione

SystemManager :: SystemManager() : EventHandler() {
  // Entro nello stato di calibrazione
  this->startCalibrating();

  // Aggiungo gli eventi osservati
  this->addObservedEvent(TIMER_EVENT);
  this->addObservedEvent(SERIAL_EVENT);
  this->addObservedEvent(PIR_DETECTION_EVENT);

  // Inizializzo le componenti hardware
  this->alarmLed = new Led(alarm_led_pin);
  this->alarmLed->turnOff();
  this->stateLed = new Led(state_led_pin);
  this->stateLed->turnOn();
  this->pir = new PirSensor(pir_pin);
  this->pir->setEnabled(false);
  this->timer = new Timer(1000000);
}

void SystemManager :: notifyObserver(Event* e) {
  eventType = e->getType();
  
  switch(eventType) {
    case SERIAL_EVENT : 
      this->handleSerialMessage((SerialMessageReceived*)e);
      break;

    case TIMER_EVENT :
      // Durante la calibrazione faccio lampeggiare il led di stato
      this->stateLed->setState(!this->stateLed->getState());
      
      // Fermo la calibrazione se è passato il tempo necessario (indentificato dalla variabile pirActivationTime)
      if((millis() - programStarted) > pirActivationTime) {
        this->endCalibrating();
      }
      
      break;

    case PIR_DETECTION_EVENT :
      if(this->state == STATE_ON) {
        this->alarmState();
        this->sendState();
      }
      
      break;

    default : break;
  }
}

void SystemManager :: startCalibrating() {
  this->state = CALIBRATING_STATE;
  programStarted = millis();
  this->timer->start();
}

void SystemManager :: endCalibrating() {
  this->timer->stop();
  this->systemOff();
  this->sendState();
}

void SystemManager :: systemOff() {
  this->stateLed->turnOff();
  this->state = STATE_OFF;
}

void SystemManager :: systemOn() {
  this->stateLed->turnOn();
  this->state = STATE_ON;
}

void SystemManager :: alarmState() {
  this->alarmLed->turnOn();
  this->state = ALARM_STATE;
}

void SystemManager :: turnAlarmOff() {
  this->alarmLed->turnOff();
  this->state = STATE_ON;
}

void SystemManager :: sendState() {
  Serial.write(STATE_RESPONSE);
  Serial.write(this->state);
  Serial.println();
}

void SystemManager :: setId(String uuid) {
  this->id = uuid;
}

void SystemManager :: handleSerialMessage(SerialMessageReceived* event) {
  serialMessage = event->getMessage();
 
  // Il codice del comando è il primo byte
  code = (int)serialMessage[0];
  
  switch(code) {
    case TURN_SYSTEM_ON : 
        if(this->state == STATE_OFF) {
          this->systemOn();
          this->sendState();
        }
        break;
        
    case TURN_SYSTEM_OFF : 
        if(this->state == STATE_ON) {
            this->systemOff(),
            this->sendState();
        }
        break;
          
          
    case TURN_ALARM_OFF : 
        if(this->state == ALARM_STATE) {
            this->turnAlarmOff();
            this->sendState();
        }
        break;
          
    case STATE_REQUEST :
        this->sendState();
        break;
        
    case ID_REQUEST:
        Serial.write(ID_RESPONSE);
        Serial.println(this->id);
        break;

    default : 
        Serial.print("Received : ");
        Serial.println(serialMessage);
        break;
  }
}

