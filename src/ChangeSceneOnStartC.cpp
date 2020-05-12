#include "ChangeSceneOnStartC.h"
#include "ComponentsManager.h"
#include "Entity.h"
#include "FactoriesFactory.h"
#include "Scene.h"

#include <json.h>

void ChangeSceneOnStartC::destroy() {
    setActive(false);
    scene_->getComponentsManager()->eraseDC(this);
}

// FACTORY INFRASTRUCTURE
ChangeSceneOnStartCFactory::ChangeSceneOnStartCFactory() = default;

Component* ChangeSceneOnStartCFactory::create(Entity* _father,
                                              Json::Value& _data,
                                              Scene* _scene) {
    ChangeSceneOnStartC* controller = new ChangeSceneOnStartC();
    _scene->getComponentsManager()->addDC(controller);

    controller->setFather(_father);
    controller->setScene(_scene);

    controller->setActive(true);

    if (_data["scene"].isString())
        _scene->changeScene(_data["scene"].asString());

    return controller;
};

DEFINE_FACTORY(ChangeSceneOnStartC);
