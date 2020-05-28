#pragma once

#include "EventComponent.h"
#include "Factory.h"

DECLARE_FACTORY(UpperWallEC)

class UpperWallEC final : public EventComponent {
  public:
    void destroy() override;
    void checkEvent() override;
};
