#pragma once

#include "Component.h"
#include "Factory.h"

#include <string>

DECLARE_FACTORY(MousePropertiesC);

class MousePropertiesC : public Component {
  private:
  public:
    MousePropertiesC() = default;
    ~MousePropertiesC() = default;

    virtual void destroy();
};