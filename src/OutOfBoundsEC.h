#pragma once

#include "EventComponent.h"
#include "Factory.h"

DECLARE_FACTORY(OutOfBoundsEC);

class OutOfBoundsEC : public EventComponent {
  private:
    int leftBorder;
    int rightBorder;

  public:
    OutOfBoundsEC() = default;
    ~OutOfBoundsEC() = default;

    virtual void checkEvent();

    virtual void destroy();
    void setLeftBorder(int _leftBorder);
    void setRightBorder(int _rightBorder);
};
