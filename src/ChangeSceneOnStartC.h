#pragma once

#include "Component.h"
#include "Factory.h"

DECLARE_FACTORY(ChangeSceneOnStartC);

class ChangeSceneOnStartC : public Component {
  public:
    ChangeSceneOnStartC() = default;
    ~ChangeSceneOnStartC() = default;

    virtual void destroy();
};