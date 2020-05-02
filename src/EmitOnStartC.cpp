#include "EmitOnStartC.h"
#include "ComponentsManager.h"
#include "Entity.h"
#include "FactoriesFactory.h"
#include "ParticleC.h"
#include "RigidbodyPC.h"
#include "Scene.h"

#include <json.h>

#include <iostream> // PROVISIONAL

void EmitOnStartC::destroy() {
    setActive(false);
    scene_->getComponentsManager()->eraseDC(this);
}

void EmitOnStartC::setParticle(std::string name) {
    reinterpret_cast<ParticleC*>(father_->getComponent("ParticleC"))
        ->emitParticles(name);
}

// FACTORY INFRASTRUCTURE
EmitOnStartCFactory::EmitOnStartCFactory() = default;

Component* EmitOnStartCFactory::create(Entity* _father, Json::Value& _data,
                                       Scene* _scene) {
    EmitOnStartC* emit = new EmitOnStartC();
    _scene->getComponentsManager()->addDC(emit);

    emit->setFather(_father);
    emit->setScene(_scene);

    if (!_data["name"].isString())
        throw std::exception("EmitOnStartC: name is not a string");
    emit->setParticle(_data["name"].asString());

    emit->setActive(true);

    return emit;
};

DEFINE_FACTORY(EmitOnStartC);
