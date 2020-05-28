#pragma once

#include "Component.h"
#include "Factory.h"

DECLARE_FACTORY(WinConditionC)

class WinConditionC final : public Component {
    bool activated_ = false;

  public:
    void destroy() override;
    void win();
};
