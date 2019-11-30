#include "PirSensor.h"
#include "EventHandlerManager.h"
#include "PirDetectionEvent.h"

long lastDetection = 0;
const long detectionDelayTime = 0;

PirSensor :: PirSensor(int pin) {
  this->pin = pin;
}

void PirSensor :: setEnabled(bool on) {
  if(on) {
    attachInterrupt(digitalPinToInterrupt(this->pin), motionDetected, RISING);
  } else {
    detachInterrupt(digitalPinToInterrupt(this->pin));
  }
}

bool PirSensor :: isDetecting() {
  return digitalRead(this->pin);
}

void motionDetected() {
  long t = millis();
  if((t - lastDetection) > detectionDelayTime) {
    lastDetection = t;
    dispatchEvent(new PirDetectionEvent());
  }
}

