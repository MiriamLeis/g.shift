#pragma once

#include "EventComponent.h"
#include "Factory.h"

DECLARE_FACTORY(OutOfBoundsEC)

class OutOfBoundsEC final : public EventComponent {
    int leftBorder_ = 0;
    int rightBorder_ = 0;

  public:
    void checkEvent() override;
    void destroy() override;
    void setLeftBorder(int leftBorder);
    void setRightBorder(int rightBorder);
};
