#pragma once

#include "EventComponent.h"
#include "Factory.h"

DECLARE_FACTORY(ReachFinalBlockEC)

class ReachFinalBlockEC final : public EventComponent {
  public:
    void checkEvent() override;
    void destroy() override;
};
