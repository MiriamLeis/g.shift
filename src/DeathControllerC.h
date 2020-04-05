#pragma once

#include "Component.h"
#include "Factory.h"

DECLARE_FACTORY(DeathControllerC);

class DeathControllerC : public Component {
  private:
    // value of the collectable
    int totalCoins_;
    // value of the collectable
    int coinsPicked_;

  public:
    DeathControllerC() = default;
    ~DeathControllerC() = default;

    virtual void destroy();

    void playerDeath();
};