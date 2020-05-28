#pragma once

#include "Component.h"
#include "Factory.h"

#include <string>

DECLARE_FACTORY(EmitOnStartC)

class EmitOnStartC final : public Component {
  public:
    void destroy() override;

    // establish the number of coins that there are in the map
    void setParticle(const std::string& name);
};