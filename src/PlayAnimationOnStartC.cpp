#include "PlayAnimationOnStartC.h"
#include "AnimationLC.h"
#include "ComponentsManager.h"
#include "Entity.h"
#include "FactoriesFactory.h"
#include "Scene.h"
#include "SoundComponent.h"

#include <json.h>

// COMPONENT CODE
void PlayAnimationOnStartC::destroy() {
    setActive(false);
    scene_->getComponentsManager()->eraseDC(this);
}

// FACTORY INFRASTRUCTURE DEFINITION

PlayAnimationOnStartCFactory::PlayAnimationOnStartCFactory() = default;

Component* PlayAnimationOnStartCFactory::create(Entity* _father,
                                                Json::Value& _data,
                                                Scene* _scene) {
    PlayAnimationOnStartC* play = new PlayAnimationOnStartC();

    _scene->getComponentsManager()->addDC(play);

    play->setFather(_father);
    play->setScene(_scene);

    if (_data["animation"].isString())
        reinterpret_cast<AnimationLC*>(_father->getComponent("AnimationLC"))
            ->startAnimation(_data["animation"].asString());

    return play;
}

DEFINE_FACTORY(PlayAnimationOnStartC)
