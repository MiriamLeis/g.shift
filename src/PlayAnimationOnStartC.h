#pragma once

#include "Component.h"
#include "Factory.h"

#include <string>

// FACTORY INFRASTRUCTURE DECLARATION
DECLARE_FACTORY(PlayAnimationOnStartC);

class PlayAnimationOnStartC : public Component {
  private:
    std::string music = "";

  public:
    PlayAnimationOnStartC() = default;
    virtual ~PlayAnimationOnStartC() = default;

    virtual void destroy();
};
