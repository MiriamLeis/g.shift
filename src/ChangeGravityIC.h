#pragma once

#include "Factory.h"
#include "InputComponent.h"

// FACTORY INFRASTRUCTURE DECLARATION
DECLARE_FACTORY(ChangeGravityIC)

namespace Ogre {
    typedef float Real;
    template <int Dims, typename T> class Vector;
    typedef Vector<3, Real> Vector3;
} // namespace Ogre

class ChangeGravityIC final : public InputComponent {
    float speed_;
    Ogre::Vector3* colourL_ = nullptr;
    Ogre::Vector3* colourR_ = nullptr;
    bool gravityTowardsLeft_ = true;

  public:
    ChangeGravityIC();
    ~ChangeGravityIC();

    // On space bar down, change the rigidbody gravity
    void handleInput(const SDL_Event& event) override;

    // Set the speed
    void setSpeed(float speed);
    // Set colours
    void setColours(Ogre::Vector3 colourL, Ogre::Vector3 colourR);
};
