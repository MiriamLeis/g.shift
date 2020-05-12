#pragma once

#include "EventComponent.h"
#include "Factory.h"

DECLARE_FACTORY(ReachFinalBlockEC);

class ReachFinalBlockEC : public EventComponent {
  public:
    ReachFinalBlockEC();
    ~ReachFinalBlockEC();

    virtual void checkEvent();
    virtual void destroy();
};
