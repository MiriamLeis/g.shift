#include "PlayMusicOnStartC.h"
#include "ComponentsManager.h"
#include "Entity.h"
#include "FactoriesFactory.h"
#include "Scene.h"
#include "SoundComponent.h"

#include <json.h>

// COMPONENT CODE
void PlayMusicOnStartC::destroy() {
    stopCurrentMusic(music_);
    setActive(false);
    scene_->getComponentsManager()->eraseDC(this);
}

void PlayMusicOnStartC::setMusic(const std::string& sound) {
    if (music_ != sound) {
        reinterpret_cast<SoundComponent*>(
            father_->getComponent("SoundComponent"))
            ->stopSound(music_);
        music_ = sound;
        reinterpret_cast<SoundComponent*>(
            father_->getComponent("SoundComponent"))
            ->playSound(music_);
    }
}

void PlayMusicOnStartC::stopCurrentMusic(const std::string& sound) {
    reinterpret_cast<SoundComponent*>(father_->getComponent("SoundComponent"))
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

DEFINE_FACTORY(PlayMusicOnStartC)
