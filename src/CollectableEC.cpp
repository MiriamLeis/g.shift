#include "CollectableEC.h"
#include "CoinCounterC.h"
#include "ComponentsManager.h"
#include "Entity.h"
#include "FactoriesFactory.h"
#include "RigidbodyPC.h"
#include "Scene.h"

#include <json.h>

void CollectableEC::destroy() {
    setActive(false);
    scene->getComponentsManager()->eraseEC(this);
}

void CollectableEC::checkEvent() {
    if (reinterpret_cast<RigidbodyPC*>(father->getComponent("RigidbodyPC"))
            ->collidesWith("Player")) {
        reinterpret_cast<CoinCounterC*>(
            scene->getEntitybyId("GameManager")->getComponent("CoinCounterC"))
            ->pickCoin();
        scene->deleteEntity(father);
    }
}

int CollectableEC::getValue() { return value_; }

void CollectableEC::setValue(int value) { value_ = value; }

// FACTORY INFRASTRUCTURE
CollectableECFactory::CollectableECFactory() = default;

Component* CollectableECFactory::create(Entity* _father, Json::Value& _data,
                                        Scene* _scene) {
    CollectableEC* collectable = new CollectableEC();
    _scene->getComponentsManager()->addEC(collectable);

    collectable->setFather(_father);
    collectable->setScene(_scene);

    if (!_data["value"].asInt())
        throw std::exception("CollectableEC: value is not an int");
    collectable->setValue(_data["value"].asInt());

    collectable->setActive(true);

    return collectable;
};

DEFINE_FACTORY(CollectableEC);