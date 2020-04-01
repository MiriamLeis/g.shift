#pragma once

#include "Component.h"
#include "Factory.h"

DECLARE_FACTORY(CoinCounterC);

class CoinCounterC : public Component {
  private:
      // value of the collectable
      int totalCoins_;
      // value of the collectable
      int coinsPicked_;

  public:
      CoinCounterC() = default;
    ~CoinCounterC() = default;

    virtual void destroy();

    // return the number of coins that is in the map, picked or not
    int getTotalCoins();
    // establish the number of coins that there are in the map
    void setTotalCoins(int total);

    // add the picked coin to the counter of picked coins
    void pickCoin();
    // return the number of coins picked
    int getCoinsPicked();
};