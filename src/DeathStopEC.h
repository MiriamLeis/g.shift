#pragma once
#include "EventComponent.h"
#include "Factory.h"

DECLARE_FACTORY(DeathStopEC)

class DeathStopEC final : public EventComponent {
  public:
    void checkEvent() override;
    void destroy() override;
};