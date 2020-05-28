#pragma once

#include "Factory.h"
#include "GuiLabelC.h"

// FACTORY INFRASTRUCTURE DECLARATION
DECLARE_FACTORY(CoinsLabelC)

class CoinsLabelC final : public GuiLabelComponent {
  public:
    void updateLabelCoins(int picked, int total);
};