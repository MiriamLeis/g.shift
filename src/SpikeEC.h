#pragma once

#include "EventComponent.h"
#include "Factory.h"

DECLARE_FACTORY(SpikeEC)

class SpikeEC final : public EventComponent {
  public:
    void destroy() override;
    void checkEvent() override;
};