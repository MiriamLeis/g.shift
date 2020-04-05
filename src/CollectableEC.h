#pragma once

#include "EventComponent.h"
#include "Factory.h"

DECLARE_FACTORY(CollectableEC);

class CollectableEC : public EventComponent {
  private:
    // value of the collectable
    int value_;

  public:
    CollectableEC() = default;
    ~CollectableEC() = default;

    virtual void destroy();

    virtual void checkEvent();

    // get the value of the collectable
    int getValue();
    // set the value of the collectable
    void setValue(int value);
};