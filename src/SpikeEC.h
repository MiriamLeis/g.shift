#pragma once

#include "EventComponent.h"
#include "Factory.h"

DECLARE_FACTORY(SpikeEC);

class SpikeEC : public EventComponent {
  private:

  public:
    SpikeEC() = default;
    ~SpikeEC() = default;

    virtual void checkEvent();
};