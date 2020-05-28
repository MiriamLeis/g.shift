#pragma once

#include "EventComponent.h"
#include "Factory.h"

DECLARE_FACTORY(CollectableEC)

class AnimationLC;
class CollectableEC final : public EventComponent {
    // value of the collectable
    int value_ = 0;

    AnimationLC* animations_ = nullptr;

  public:
    void destroy() override;

    void checkEvent() override;

    // get the value of the collectable
    int getValue();
    // set the value of the collectable
    void setValue(int value);

    // set animations from father AnimationLC
    void setAnimations();

    // play idle animation
    void playAnimation();
};