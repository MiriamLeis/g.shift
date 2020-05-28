#pragma once

#include "Component.h"
#include "Factory.h"

DECLARE_FACTORY(ChangeSceneOnStartC)

class ChangeSceneOnStartC final : public Component {
  public:
    void destroy() override;
};