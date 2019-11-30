#include "Event.h"
#include "EventHandlerManager.h"
#include "SerialMessageReceived.h"
#include "SystemManager.h"
#include "TimerOne.h"
#include "SettingsManager.h"
#include "EEPROM.h"
#include "TrueRandom.h"

String input = "";
String uuid = "";
SystemManager* systemManager;
SettingsManager* settings;

void setup() {
  Serial.begin(9600);
  input.reserve(20);
  systemManager = new SystemManager();
  settings = new SettingsManager();

  // Controllo se in memoria è salvato l'UUID del sistema. 
  if(settings->needUUID()) {
    /* 
     * Se la memoria EEPROM non è mai stata usata ogni cella contiene il valore 255. 
     * Con questa operazione scrivo su ogni cella il valore 0 in modo da marcarla come pulita
     */
    settings->clearEEPROM();
    uuid = generateUUID();
    settings->saveUUID(uuid);
  } else {
    uuid = settings->loadUUID();
  }

  systemManager->setId(uuid);
  addEventHandler(systemManager);
}

void loop() {
  mainEventLoop();
}

/* 
 * Funzione di Arduino invocata quando sono disponibili dati sulla seriale
 * Il controllo viene eseguito come ultima istruzione della funzione loop
 */
void serialEvent() {
  input = Serial.readStringUntil('\n');
  dispatchEvent(new SerialMessageReceived(input));
}
