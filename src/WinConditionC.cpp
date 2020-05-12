#include "WinConditionC.h"
#include "ComponentsManager.h"
#include "Entity.h"
#include "FactoriesFactory.h"
#include "PlayMusicOnStartC.h"
#include "RigidbodyPC.h"
#include "Scene.h"

#include <json.h>

void WinConditionC::destroy() {
    setActive(false);
    scene_->getComponentsManager()->eraseDC(this);
}

void WinConditionC::win() {
    if (!activated) {
        activated = true;
        scene_->changeScene("WinMenu");
        dynamic_cast<PlayMusicOnStartC*>(
            scene_->getEntityById("MusicManager")
                ->getComponent("PlayMusicOnStartC"))
            ->setMusic("menuMusic");
    }
}

// FACTROY INFRASTRUCTURE
WinConditionCFactory::WinConditionCFactory() = default;

Component* WinConditionCFactory::create(Entity* _father, Json::Value& _data,
                                        Scene* _scene) {
    WinConditionC* winCondition = new WinConditionC();
    _scene->getComponentsManager()->addDC(winCondition);

    winCondition->setFather(_father);
    winCondition->setScene(_scene);

    winCondition->setActive(false);

    return winCondition;
}

DEFINE_FACTORY(WinConditionC);
