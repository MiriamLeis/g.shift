#pragma once

#include "Component.h"
#include "Factory.h"

DECLARE_FACTORY(WinConditionC);

class WinConditionC : public Component {
  private:
    bool activated = false;

  public:
    WinConditionC() = default;
    ~WinConditionC() = default;

    virtual void destroy();

    void win();
};
