#include "Event.h"
#include "Arduino.h"

#ifndef __SERIALMESSAGE__
#define __SERIALMESSAGE__

/*
 * Evento generato quando viene ricevuto un messaggio dalla seriale
 */
class SerialMessageReceived : public Event {

  public:
    SerialMessageReceived(String message);
    String getMessage();

  private:
    String message;
};

#endif

