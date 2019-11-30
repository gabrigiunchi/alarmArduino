#ifndef __SYSTEMMANAGER__
#define __SYSTEMMANAGER__

#include "EventHandler.h"
#include "Event.h"
#include "Timer.h"
#include "Led.h"
#include "Arduino.h"
#include "PirSensor.h"
#include "SerialMessageReceived.h"

#define MAX_OBSERVED_EVENTS 10

/*
 * Classe che gestisce le componenti del sistema per implementare il comportamento dell'applicazione.
 * In particolare è registrato come event handler dei seguenti tipi di eventi:
 * 
 * - SerialEvent
 * - PirDetectionEvent
 * - TimerEvent
 */
class SystemManager : public EventHandler {

  public:
    SystemManager();
    void notifyObserver(Event* e);
    void setId(String uuid);

  private:
    int state;
    Led* alarmLed;
    Led* stateLed;
    Timer* timer;
    PirSensor* pir;
    String id;
    
    void startCalibrating();
    void endCalibrating();
    void systemOn();
    void systemOff();
    void alarmState();
    void turnAlarmOff();
    void sendState();
    void handleSerialMessage(SerialMessageReceived* message);
};

#endif
