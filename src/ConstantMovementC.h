#pragma once
#include "Component.h"
#include "Factory.h"

DECLARE_FACTORY(ConstantMovementC)

class ConstantMovementC final : public Component {
    float speed_ = 0.0f;

  public:
    void destroy() override;

    // getter / Setters
    void setSpeed(float speed);

    float getSpeed();
};
