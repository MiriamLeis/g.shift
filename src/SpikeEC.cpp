#include "SpikeEC.h"
#include "ComponentsManager.h"
#include "Entity.h"
#include "FactoriesFactory.h"
#include "RigidbodyPC.h"
#include "Scene.h"

#include <iostream> // PROVISIONAL

void SpikeEC::checkEvent() {
    if (reinterpret_cast<RigidbodyPC*>(father->getComponent("RigidbodyPC"))
            ->collidesWith("Player")) {
        // scene->deleteEntity(scene->getEntitybyId("Player"));
        std::cout << "\n PLAYER DEAD \n"; // PROVISIONAL
    }
}

// FACTORY INFRASTRUCTURE
SpikeECFactory::SpikeECFactory() = default;

Component* SpikeECFactory::create(Entity* _father, Json::Value& _data,
                                  Scene* _scene) {
    SpikeEC* spikes = new SpikeEC();
    _scene->getComponentsManager()->addEC(spikes);

    spikes->setFather(_father);
    spikes->setScene(_scene);

    spikes->setActive(true);

    return spikes;
};

DEFINE_FACTORY(SpikeEC);