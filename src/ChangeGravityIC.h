#pragma once

#include "Factory.h"
#include "InputComponent.h"
#include <string>

#include "Factory.h"

// FACTORY INFRASTRUCTURE DECLARATION
DECLARE_FACTORY(ChangeGravityIC);
namespace Ogre {
    typedef float Real;
    template <int dims, typename T> class Vector;
    typedef Vector<3, Real> Vector3;
} // namespace Ogre

class ChangeGravityIC : public InputComponent {
  private:
    float speed;
    Ogre::Vector3 *colourL_ = nullptr, *colourR_ = nullptr;
    bool movingIzq = true;

  public:
    ChangeGravityIC();
    virtual ~ChangeGravityIC();

    // On space bar down, change the rigibody gravity
    virtual void handleInput(const SDL_Event& _event);

    // Set the speed
    void setSpeed(float _speed);
    // Set colours
    void setColours(Ogre::Vector3 colourL, Ogre::Vector3 colourR);
};
