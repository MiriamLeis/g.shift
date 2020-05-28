#pragma once
#include "EventComponent.h"
#include "Factory.h"

DECLARE_FACTORY(ExitWithEscapeEC)

class GuiLabelComponent;
class ExitWithEscapeEC final : public EventComponent {
    float timeToExit_ = 2.0f;
    float startTime_ = 0;
    bool pressing_ = false;
    bool out_ = false;
    GuiLabelComponent* label_ = nullptr;

  public:
    void setPress(bool press);
    void setAlpha();
    void checkEvent() override;
};