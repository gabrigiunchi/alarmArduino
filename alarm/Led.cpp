#include "Led.h"
#include "Arduino.h"

Led :: Led(int pin) {
  pinMode(pin, OUTPUT);
  this->pin = pin;
}

int Led :: getState() {
  return digitalRead(this->pin);
}

void Led :: setState(int state) {
  digitalWrite(this->pin, state);
}

bool Led :: isOn() {
  return this->getState() == HIGH;
}

void Led :: turnOn() {
  digitalWrite(this->pin, HIGH);
}

void Led :: turnOff() {
  digitalWrite(this->pin, LOW);
}

