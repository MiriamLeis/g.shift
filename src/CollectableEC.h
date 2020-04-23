#pragma once

#include "EventComponent.h"
#include "Factory.h"

DECLARE_FACTORY(CollectableEC);

class AnimationLC;
class CollectableEC : public EventComponent {
  private:
    // value of the collectable
    int value_;

    AnimationLC* animations = nullptr;

  public:
    CollectableEC() = default;
    ~CollectableEC() = default;

    virtual void destroy();

    virtual void checkEvent();

    // get the value of the collectable
    int getValue();
    // set the value of the collectable
    void setValue(int value);

    // set animations from father AnimationLC
    void setAnimations();

    // play idle animation
    void playAnimation();
};