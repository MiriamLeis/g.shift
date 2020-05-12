#include "UpperWallEC.h"
#include "ComponentsManager.h"
#include "Entity.h"
#include "FactoriesFactory.h"
#include "RigidbodyPC.h"
#include "Scene.h"
#include "WinConditionC.h"

void UpperWallEC::destroy() {
    setActive(false);
    scene_->getComponentsManager()->eraseEC(this);
}

void UpperWallEC::checkEvent() {
    if (reinterpret_cast<RigidbodyPC*>(father_->getComponent("RigidbodyPC"))
            ->collidesWith("Player")) {
        reinterpret_cast<WinConditionC*>(
            scene_->getEntityById("GameManager")->getComponent("WinConditionC"))
            ->win();
    }
}

// FACTORY INFRASTRUCTURE
UpperWallECFactory::UpperWallECFactory() = default;

Component* UpperWallECFactory::create(Entity* _father, Json::Value& _data,
                                      Scene* _scene) {
    UpperWallEC* upperWall = new UpperWallEC();
    _scene->getComponentsManager()->addEC(upperWall);

    upperWall->setFather(_father);
    upperWall->setScene(_scene);
    upperWall->setActive(true);

    return upperWall;
}

DEFINE_FACTORY(UpperWallEC);
