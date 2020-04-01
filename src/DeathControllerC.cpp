#include "DeathControllerC.h"
#include "ComponentsManager.h"
#include "Entity.h"
#include "FactoriesFactory.h"
#include "RigidbodyPC.h"
#include "Scene.h"

#include <json.h>

#include <iostream> // PROVISIONAL

void DeathControllerC::destroy() {
    setActive(false);
    scene->getComponentsManager()->eraseDC(this);
}

void DeathControllerC::playerDeath()
{
    scene->changeScene("DeadMenu");
    std::cout << "\n PLAYER DEAD \n"; // PROVISIONAL
}

// FACTORY INFRASTRUCTURE
DeathControllerCFactory::DeathControllerCFactory() = default;

Component* DeathControllerCFactory::create(Entity* _father, Json::Value& _data,
                                  Scene* _scene) {
    DeathControllerC* controller = new DeathControllerC();
    _scene->getComponentsManager()->addDC(controller);

    controller->setFather(_father);
    controller->setScene(_scene);

    controller->setActive(true);

    return controller;
};

DEFINE_FACTORY(DeathControllerC);

