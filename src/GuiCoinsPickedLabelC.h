#pragma once

#include "Factory.h"
#include "GuiLabelC.h"

// FACTORY INFRASTRUCTURE DECLARATION
DECLARE_FACTORY(GuiCoinsPickedLabelC)

class GuiCoinsPickedLabelC final : public GuiLabelComponent {
  public:
    void createText();
};