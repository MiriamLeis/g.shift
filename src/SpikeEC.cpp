#include "SpikeEC.h"
#include "ComponentsManager.h"
#include "DeathControllerC.h"
#include "Entity.h"
#include "FactoriesFactory.h"
#include "RigidbodyPC.h"
#include "Scene.h"

void SpikeEC::destroy() {
    setActive(false);
    scene_->getComponentsManager()->eraseEC(this);
}

void SpikeEC::checkEvent() {
    if (reinterpret_cast<RigidbodyPC*>(father_->getComponent("RigidbodyPC"))
            ->collidesWith("Player")) {
        reinterpret_cast<DeathControllerC*>(
            scene_->getEntityById("GameManager")
                ->getComponent("DeathControllerC"))
            ->playerDeath();
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