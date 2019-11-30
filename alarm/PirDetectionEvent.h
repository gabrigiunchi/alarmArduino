#ifndef __PIREVENT__
#define __PIREVENT__

#include "Event.h"

/*
 * Evento generato quando un sensore pin individua un movimento
 */
class PirDetectionEvent : public Event {
  public:
    PirDetectionEvent();
};

#endif
