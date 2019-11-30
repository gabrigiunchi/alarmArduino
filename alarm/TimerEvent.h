#ifndef __TIMEREVENT__
#define __TIMEREVENT__

#include "Event.h"

/*
 * Evento generato allo scadere del timer
 */
class TimerEvent : public Event {

  public:
    TimerEvent();
};

#endif
