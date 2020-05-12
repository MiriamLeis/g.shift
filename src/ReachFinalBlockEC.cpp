#include "ReachFinalBlockEC.h"
#include "ComponentsManager.h"
#include "Entity.h"
#include "FactoriesFactory.h"
#include "Factory.h"
#include "OgreRoot.h"
#include "RigidbodyPC.h"
#include "Scene.h"
#include "WinConditionC.h"
#include <iostream>
#include <json.h>

ReachFinalBlockEC::ReachFinalBlockEC() {}

ReachFinalBlockEC::~ReachFinalBlockEC() {}

void ReachFinalBlockEC::checkEvent() {
    Entity* player = scene_->getEntityById("Player");
    auto rigid =
        reinterpret_cast<RigidbodyPC*>(player->getComponent("RigidbodyPC"));
    if (rigid->getLinearVelocity().y <= 0)
        reinterpret_cast<WinConditionC*>(
            scene_->getEntityById("GameManager")->getComponent("WinConditionC"))
            ->win();
}

void ReachFinalBlockEC::destroy() {
    setActive(false);
    scene_->getComponentsManager()->eraseEC(this);
}

// FACTROY INFRASTRUCTURE
ReachFinalBlockECFactory::ReachFinalBlockECFactory() = default;

Component* ReachFinalBlockECFactory::create(Entity* _father, Json::Value& _data,
                                            Scene* _scene) {
    ReachFinalBlockEC* finalBlock = new ReachFinalBlockEC();

    _scene->getComponentsManager()->addEC(finalBlock);
    finalBlock->setFather(_father);
    finalBlock->setScene(_scene);

    finalBlock->setActive(true);

    return finalBlock;
}

DEFINE_FACTORY(ReachFinalBlockEC);
