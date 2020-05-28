#pragma once

#include "Component.h"
#include "Factory.h"

DECLARE_FACTORY(CoinCounterC)

class CoinCounterC final : public Component {
    // value of the collectable
    int totalCoins_ = 0;
    // value of the collectable
    int coinsPicked_ = 0;

  public:
    void destroy() override;

    // return the number of coins that is in the map, picked or not
    int getTotalCoins();
    // establish the number of coins that there are in the map
    void setTotalCoins(int total);

    // add the picked coin to the counter of picked coins
    void pickCoin();
    // return the number of coins picked
    int getCoinsPicked();
};