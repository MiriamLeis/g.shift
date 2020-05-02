#include "ChangeGravityIC.h"
#include "AmbientLightC.h"
#include "ComponentsManager.h"
#include "ConstantMovementC.h"
#include "Entity.h"
#include "FactoriesFactory.h"
#include "OgreRoot.h"
#include "RigidbodyPC.h"
#include "Scene.h"
#include "TridimensionalObjectRC.h"

#include <iostream>
#include <json.h>

ChangeGravityIC::ChangeGravityIC() {
    colourL_ = new Ogre::Vector3();
    colourR_ = new Ogre::Vector3();
}

ChangeGravityIC::~ChangeGravityIC() {
    delete colourL_;
    delete colourR_;
}

void ChangeGravityIC::handleInput(const SDL_Event& _event) {
    if (_event.type == SDL_KEYDOWN && _event.key.keysym.sym == SDLK_SPACE) {
        movingIzq = !movingIzq;

        RigidbodyPC* body = reinterpret_cast<RigidbodyPC*>(
            father_->getComponent("RigidbodyPC"));

        body->setGravity(!movingIzq ? Ogre::Vector3(speed, 0.0f, 0.0f)
                                    : Ogre::Vector3(-speed, 0.0f, 0.0f));

        Ogre::Vector3 velocity = body->getLinearVelocity();

        body->setLinearVelocity(Ogre::Vector3(0.0f, velocity.y, 0.0f));

        reinterpret_cast<AmbientLightC*>(
            scene_->getEntityById("Light")->getComponent("AmbientLightC"))
            ->setColour(!movingIzq ? *colourR_ : *colourL_);
    }
}

void ChangeGravityIC::setSpeed(float _speed) { speed = _speed; }

void ChangeGravityIC::setColours(Ogre::Vector3 colourL, Ogre::Vector3 colourR) {
    *colourL_ = colourL;
    *colourR_ = colourR;
}

// FACTORY INFRASTRUCTURE

ChangeGravityICFactory::ChangeGravityICFactory() = default;

Component* ChangeGravityICFactory::create(Entity* _father, Json::Value& _data,
                                          Scene* scene) {
    ChangeGravityIC* changeGravity = new ChangeGravityIC();
    scene->getComponentsManager()->addIC(changeGravity);

    changeGravity->setFather(_father);
    changeGravity->setScene(scene);

    if (!_data["speed"].isDouble())
        throw std::exception("ChangeGravityIC: speed is not a double");
    changeGravity->setSpeed(_data["speed"].asDouble());

    if (!_data["colourL"].isArray() || !_data["colourL"][0].isDouble())
        throw std::exception(
            "ChangeGravityIC: colourL is not an array of doubles");
    if (!_data["colourR"].isArray() || !_data["colourR"][0].isDouble())
        throw std::exception(
            "ChangeGravityIC: colourL is not an array of doubles");
    changeGravity->setColours(Ogre::Vector3(_data["colourL"][0].asFloat(),
                                            _data["colourL"][1].asFloat(),
                                            _data["colourL"][2].asFloat()),
                              Ogre::Vector3(_data["colourR"][0].asFloat(),
                                            _data["colourR"][1].asFloat(),
                                            _data["colourR"][2].asFloat()));

    return changeGravity;
};

DEFINE_FACTORY(ChangeGravityIC);