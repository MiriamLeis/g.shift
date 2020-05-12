#pragma once

#include "EventComponent.h"
#include "Factory.h"

DECLARE_FACTORY(UpperWallEC);

class UpperWallEC : public EventComponent {
  public:
    UpperWallEC() = default;
    ~UpperWallEC() = default;

    virtual void destroy();
    virtual void checkEvent();
};
