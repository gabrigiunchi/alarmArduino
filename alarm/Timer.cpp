#include "TimerOne.h"
#include "Timer.h"
#include "TimerEvent.h"
#include "EventHandlerManager.h"

Timer :: Timer(long period) {
  Timer1.initialize(period);
}

void Timer :: setPeriod(long period) {
  Timer1.setPeriod(period);
}

void Timer :: start() {
  Timer1.attachInterrupt(timerInterrupt);
}

void Timer :: stop() {
  Timer1.detachInterrupt();
}

void timerInterrupt() {
  dispatchEvent(new TimerEvent());
}

