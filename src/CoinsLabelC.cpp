#include "CoinsLabelC.h"
#include "CoinCounterC.h"
#include "ComponentsManager.h"
#include "Entity.h"
#include "FactoriesFactory.h"
#include "GuiContext.h"
#include "GuiLabelC.h"
#include "Scene.h"
#include <iostream>
#include <json.h>

void CoinsLabelC::updateLabelCoins(int picked, int total) {
    changeText(std::to_string(picked) + "/" + std::to_string(total));
}

// FACTORY INFRASTRUCTURE DEFINITION

CoinsLabelCFactory::CoinsLabelCFactory() = default;

Component* CoinsLabelCFactory::create(Entity* _father, Json::Value& _data,
                                      Scene* _scene) {
    CoinsLabelC* coins = new CoinsLabelC();

    _scene->getComponentsManager()->addDC(coins);
    coins->setFather(_father);
    coins->setScene(_scene);

    coins->setText("0/" +
                   std::to_string(reinterpret_cast<CoinCounterC*>(
                                      _scene->getEntityById("CoinManager")
                                          ->getComponent("CoinCounterC"))
                                      ->getTotalCoins()));

    if (!_data["position"].isArray())
        throw std::exception("GuiCoinsPickedLabelC: position is not an array");
    coins->setPosition(glm::vec2(_data["position"][0].asFloat(),
                                 _data["position"][1].asFloat()));

    if (!_data["size"].isArray())
        throw std::exception("GuiCoinsPickedLabelC: size is not an array");
    coins->setSize(
        glm::vec2(_data["size"][0].asFloat(), _data["size"][1].asFloat()));

    if (!_data["name"].isString())
        throw std::exception("GuiCoinsPickedLabelC: name is not a string");
    coins->setName(_data["name"].asString());

    coins->create();

    if (_data["onTop"].isBool())
        if (_data["onTop"].asBool())
            coins->moveToFront();
        else
            coins->moveToBack();

    if (_data["alwaysOnTop"].isBool() && _data["alwaysOnTop"].asBool())
        coins->AlwaysOnTop();

    return coins;
}

DEFINE_FACTORY(CoinsLabelC)
