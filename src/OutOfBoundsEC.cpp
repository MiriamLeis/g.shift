#include "OutOfBoundsEC.h"
#include "ComponentsManager.h"
#include "DeathControllerC.h"
#include "Entity.h"
#include "FactoriesFactory.h"
#include "OgreRoot.h"
#include "Scene.h"
#include "TransformComponent.h"

#include <json.h>

void OutOfBoundsEC::checkEvent() {
    TransformComponent* transform = reinterpret_cast<TransformComponent*>(
        scene->getEntitybyId("Player")->getComponent("TransformComponent"));

    if (transform->getPosition().x > rightBorder ||
        transform->getPosition().x < leftBorder) {
        reinterpret_cast<DeathControllerC*>(
            scene->getEntitybyId("Player")->getComponent("DeathControllerC"))
            ->playerDeath();
    }
}

void OutOfBoundsEC::setLeftBorder(int _leftBorder) { leftBorder = _leftBorder; }

void OutOfBoundsEC::setRightBorder(int _rightBorder) {
    rightBorder = _rightBorder;
}

// FACTORY INFRASTRUCTURE
OutOfBoundsECFactory::OutOfBoundsECFactory() = default;

Component* OutOfBoundsECFactory::create(Entity* _father, Json::Value& _data,
                                        Scene* _scene) {
    OutOfBoundsEC* outOfBounds = new OutOfBoundsEC();
    _scene->getComponentsManager()->addEC(outOfBounds);

    outOfBounds->setFather(_father);
    outOfBounds->setScene(_scene);

    if (!_data["LeftBorder"].asInt())
        throw std::exception("OutOfBoundsEC: leftBorder is not an int");
    outOfBounds->setLeftBorder(_data["LeftBorder"].asInt());

    if (!_data["RightBorder"].asInt())
        throw std::exception("OutOfBoundsEC: rightBorder is not an int");
    outOfBounds->setRightBorder(_data["RightBorder"].asInt());

    outOfBounds->setActive(true);

    return outOfBounds;
}

DEFINE_FACTORY(OutOfBoundsEC);