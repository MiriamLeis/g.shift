#include "DeathControllerC.h"
#include "ComponentsManager.h"
#include "Entity.h"
#include "FactoriesFactory.h"
#include "PlayMusicOnStartC.h"
#include "Scene.h"

#include <json.h>

void DeathControllerC::destroy() {
    setActive(false);
    scene_->getComponentsManager()->eraseDC(this);
}

void DeathControllerC::playerDeath() {
    if (!activated_) {
        activated_ = true;
        scene_->changeScene("DeadMenu");
        reinterpret_cast<PlayMusicOnStartC*>(
            scene_->getEntityById("MusicManager")
                ->getComponent("PlayMusicOnStartC"))
            ->setMusic("endMusic");
    }
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

DEFINE_FACTORY(DeathControllerC)
