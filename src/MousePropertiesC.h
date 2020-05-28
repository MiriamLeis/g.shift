#pragma once

#include "Component.h"
#include "Factory.h"

DECLARE_FACTORY(MousePropertiesC)

class MousePropertiesC final : public Component {
  public:
    void destroy() override;
};