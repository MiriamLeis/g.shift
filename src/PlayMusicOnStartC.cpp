#include "PlayMusicOnStartC.h"
#include "ComponentsManager.h"
#include "Entity.h"
#include "FactoriesFactory.h"
#include "OgreEntity.h"
#include "OgreSDLContext.h"
#include "Scene.h"
#include "SoundComponent.h"
#include "TransformComponent.h"

#include <OgreSceneManager.h>
#include <json.h>

// COMPONENT CODE
void PlayMusicOnStartC::destroy() {
    stopCurrentMusic(music);
    setActive(false);
    scene_->getComponentsManager()->eraseDC(this);
}

void PlayMusicOnStartC::setMusic(std::string sound) {
    if (music != sound) {
        dynamic_cast<SoundComponent*>(father_->getComponent("SoundComponent"))
            ->stopSound(music);
        music = sound;
        dynamic_cast<SoundComponent*>(father_->getComponent("SoundComponent"))
            ->playSound(music);
    }
}

void PlayMusicOnStartC::stopCurrentMusic(std::string sound) {
    dynamic_cast<SoundComponent*>(father_->getComponent("SoundComponent"))
        ->stopSound(sound);
}

// FACTORY INFRASTRUCTURE DEFINITION

PlayMusicOnStartCFactory::PlayMusicOnStartCFactory() = default;

Component* PlayMusicOnStartCFactory::create(Entity* _father, Json::Value& _data,
                                            Scene* _scene) {
    PlayMusicOnStartC* play = new PlayMusicOnStartC();

    _scene->getComponentsManager()->addDC(play);

    play->setFather(_father);
    play->setScene(_scene);

    if (!_data["sound"].isString())
        throw std::exception("PlayMusicOnStartC: sound is not a string");
    play->setMusic(_data["sound"].asString());

    return play;
}

DEFINE_FACTORY(PlayMusicOnStartC);
