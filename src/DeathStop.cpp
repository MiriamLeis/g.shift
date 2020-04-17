#include "DeathStop.h"
#include "ComponentsManager.h"
#include "Entity.h"
#include "FactoriesFactory.h"
#include "Factory.h"
#include "OgreRoot.h"
#include "RigidbodyPC.h"
#include "Scene.h"
#include <iostream>
#include <json.h>

DeathStopEC::DeathStopEC() {}

DeathStopEC::~DeathStopEC() {}

void DeathStopEC::checkEvent() {
    Entity* player = scene->getEntitybyId("Player");
    auto rigid =
        reinterpret_cast<RigidbodyPC*>(player->getComponent("RigidbodyPC"));
    if (rigid->getLinearVelocity().y <= 0)
        playerDeath();
}

void DeathStopEC::destroy() {
    setActive(false);
    scene->getComponentsManager()->eraseEC(this);
}

void DeathStopEC::playerDeath() {
    scene->changeScene("DeadMenu");
    std::cout << "\n PLAYER DEAD \n"; // PROVISIONAL
}

DeathStopECFactory::DeathStopECFactory() = default;

Component* DeathStopECFactory::create(Entity* _father, Json::Value& _data,
                                      Scene* _scene) {
    DeathStopEC* deathStop = new DeathStopEC();
    _scene->getComponentsManager()->addEC(deathStop);

    deathStop->setFather(_father);
    deathStop->setScene(_scene);

    deathStop->setActive(true);

    return deathStop;
};

DEFINE_FACTORY(DeathStopEC);
