#include "SerialMessageReceived.h"
#include "EventsCode.h"

SerialMessageReceived :: SerialMessageReceived(String s) : Event(SERIAL_EVENT) {
  this->message = s;
}

String SerialMessageReceived :: getMessage() {
  return this->message;
}

