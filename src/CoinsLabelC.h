#pragma once

#include "Factory.h"
#include "GuiLabelC.h"
#include <glm/glm.hpp>
#include <string>

// FACTORY INFRASTRUCTURE DECLARATION
DECLARE_FACTORY(CoinsLabelC);

class CoinsLabelC final : public GuiLabelComponent {
  private:
  public:
    CoinsLabelC() = default;
    ~CoinsLabelC() = default;

    void updateLabelCoins(int picked, int total);
};