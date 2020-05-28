#include "OutOfBoundsEC.h"
#include "ComponentsManager.h"
#include "DeathControllerC.h"
#include "Entity.h"
#include "FactoriesFactory.h"
#include "Scene.h"
#include "TransformComponent.h"

#include <json.h>

void OutOfBoundsEC::checkEvent() {
    TransformComponent* transform = reinterpret_cast<TransformComponent*>(
        scene_->getEntityById("Player")->getComponent("TransformComponent"));

    const int x = static_cast<int>(transform->getPosition().x);
    if (x > rightBorder_ || x < leftBorder_) {
        reinterpret_cast<DeathControllerC*>(
            scene_->getEntityById("GameManager")
                ->getComponent("DeathControllerC"))
            ->playerDeath();
    }
}

void OutOfBoundsEC::destroy() {
    setActive(false);
    scene_->getComponentsManager()->eraseEC(this);
}

void OutOfBoundsEC::setLeftBorder(const int leftBorder) {
    leftBorder_ = leftBorder;
}

void OutOfBoundsEC::setRightBorder(const int rightBorder) {
    rightBorder_ = rightBorder;
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

DEFINE_FACTORY(OutOfBoundsEC)
