#pragma once

#include "Component.h"
#include "Factory.h"

#include <string>

DECLARE_FACTORY(EmitOnStartC);

class EmitOnStartC : public Component {
  private:
  public:
    EmitOnStartC() = default;
    ~EmitOnStartC() = default;

    virtual void destroy();

    // establish the number of coins that there are in the map
    void setParticle(std::string name);
};