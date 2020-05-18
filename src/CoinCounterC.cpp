#include "CoinCounterC.h"
#include "CoinsLabelC.h"
#include "ComponentsManager.h"
#include "Entity.h"
#include "FactoriesFactory.h"
#include "RigidbodyPC.h"
#include "Scene.h"

#include <json.h>

#include <iostream> // PROVISIONAL

void CoinCounterC::destroy() {
    setActive(false);
    scene_->getComponentsManager()->eraseDC(this);
}

int CoinCounterC::getTotalCoins() { return totalCoins_; }

void CoinCounterC::setTotalCoins(int total) { totalCoins_ = total; }

void CoinCounterC::pickCoin() {
    coinsPicked_++;
    reinterpret_cast<CoinsLabelC*>(
        scene_->getEntityById("CoinCounter")->getComponent("CoinsLabelC"))
        ->updateLabelCoins(coinsPicked_, totalCoins_);
}

int CoinCounterC::getCoinsPicked() { return coinsPicked_; }

// FACTORY INFRASTRUCTURE
CoinCounterCFactory::CoinCounterCFactory() = default;

Component* CoinCounterCFactory::create(Entity* _father, Json::Value& _data,
                                       Scene* _scene) {
    CoinCounterC* counter = new CoinCounterC();
    _scene->getComponentsManager()->addDC(counter);

    counter->setFather(_father);
    counter->setScene(_scene);

    if (!_data["totalCoins"].asInt())
        throw std::exception("CollectableEC: totalCoins is not an int");
    counter->setTotalCoins(_data["totalCoins"].asInt());

    counter->setActive(true);

    return counter;
};

DEFINE_FACTORY(CoinCounterC);
