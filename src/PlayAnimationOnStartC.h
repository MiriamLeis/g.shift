#pragma once

#include "Component.h"
#include "Factory.h"

#include <string>

// FACTORY INFRASTRUCTURE DECLARATION
DECLARE_FACTORY(PlayAnimationOnStartC)

class PlayAnimationOnStartC final : public Component {
    std::string music_ = "";

  public:
    void destroy() override;
};
