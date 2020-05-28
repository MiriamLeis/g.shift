#include "MousePropertiesC.h"
#include "ComponentsManager.h"
#include "Entity.h"
#include "FactoriesFactory.h"
#include "GuiContext.h"
#include "Scene.h"

#include <json.h>

#include <iostream> // PROVISIONAL

void MousePropertiesC::destroy() {
    setActive(false);
    scene_->getComponentsManager()->eraseDC(this);
}

// FACTORY INFRASTRUCTURE
MousePropertiesCFactory::MousePropertiesCFactory() = default;

Component* MousePropertiesCFactory::create(Entity* _father, Json::Value& _data,
                                           Scene* _scene) {
    MousePropertiesC* mouse = new MousePropertiesC();
    _scene->getComponentsManager()->addDC(mouse);

    mouse->setFather(_father);
    mouse->setScene(_scene);

    if (_data["visible"].isBool())
        GuiContext::getInstance()->setMouseVisibility(
            _data["visible"].asBool());

    mouse->setActive(true);

    return mouse;
};

DEFINE_FACTORY(MousePropertiesC)
