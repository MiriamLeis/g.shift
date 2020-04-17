#pragma once
#include "EventComponent.h"
#include "Factory.h"

DECLARE_FACTORY(DeathStopEC);

class DeathStopEC : public EventComponent {
  public:
    DeathStopEC();
    ~DeathStopEC();
    virtual void checkEvent();
    virtual void destroy();
    void playerDeath();
};