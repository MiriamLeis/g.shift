#include "ConstantMovementC.h"

#include "Component.h"
#include "ComponentsManager.h"
#include "Entity.h"
#include "FactoriesFactory.h"
#include "RigidbodyPC.h"
#include "Scene.h"

#include <json.h>

void ConstantMovementC::destroy() {
    setActive(false);
    scene_->getComponentsManager()->eraseDC(this);
}

void ConstantMovementC::setSpeed(float speed) {
    speed_ = speed;

    RigidbodyPC* body =
        dynamic_cast<RigidbodyPC*>(father_->getComponent("RigidbodyPC"));

    body->setLinearVelocity(Ogre::Vector3(0.0f, speed_, 0.0f));
}

float ConstantMovementC::getSpeed() { return speed_; }

// FACTORY INFRASTRUCTURE

ConstantMovementCFactory::ConstantMovementCFactory() = default;

Component* ConstantMovementCFactory::create(Entity* _father, Json::Value& _data,
                                            Scene* _scene) {
    ConstantMovementC* constantMovementPC = new ConstantMovementC();
    _scene->getComponentsManager()->addDC(constantMovementPC);

    constantMovementPC->setFather(_father);
    constantMovementPC->setScene(_scene);

    if (!_data["speed"].asInt())
        throw std::exception("ConstantMovementC: speed is not an int");
    constantMovementPC->setSpeed(_data["speed"].asFloat());

    return constantMovementPC;
};

DEFINE_FACTORY(ConstantMovementC)
