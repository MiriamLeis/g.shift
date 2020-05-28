#include "GuiCoinsPickedLabelC.h"
#include "CoinCounterC.h"
#include "ComponentsManager.h"
#include "Entity.h"
#include "FactoriesFactory.h"
#include "GuiContext.h"
#include "GuiLabelC.h"
#include "Scene.h"
#include <iostream>
#include <json.h>

void GuiCoinsPickedLabelC::createText() {
    int coins =
        reinterpret_cast<CoinCounterC*>(
            scene_->getEntityById("CoinManager")->getComponent("CoinCounterC"))
            ->getCoinsPicked();
    int totalCoins =
        reinterpret_cast<CoinCounterC*>(
            scene_->getEntityById("CoinManager")->getComponent("CoinCounterC"))
            ->getTotalCoins();

    std::string coinsPicked =
        std::to_string(coins) + "/" + std::to_string(totalCoins);

    setText(coinsPicked);
}

// FACTORY INFRASTRUCTURE DEFINITION

GuiCoinsPickedLabelCFactory::GuiCoinsPickedLabelCFactory() = default;

Component* GuiCoinsPickedLabelCFactory::create(Entity* _father,
                                               Json::Value& _data,
                                               Scene* _scene) {
    GuiCoinsPickedLabelC* coinPickedLabel = new GuiCoinsPickedLabelC();

    _scene->getComponentsManager()->addDC(coinPickedLabel);
    coinPickedLabel->setFather(_father);
    coinPickedLabel->setScene(_scene);

    if (!_data["position"].isArray())
        throw std::exception("GuiCoinsPickedLabelC: position is not an array");
    coinPickedLabel->setPosition(glm::vec2(_data["position"][0].asFloat(),
                                           _data["position"][1].asFloat()));

    if (!_data["size"].isArray())
        throw std::exception("GuiCoinsPickedLabelC: size is not an array");
    coinPickedLabel->setSize(
        glm::vec2(_data["size"][0].asFloat(), _data["size"][1].asFloat()));

    if (!_data["name"].isString())
        throw std::exception("GuiCoinsPickedLabelC: name is not a string");
    coinPickedLabel->setName(_data["name"].asString());

    coinPickedLabel->createText();
    coinPickedLabel->create();

    return coinPickedLabel;
}

DEFINE_FACTORY(GuiCoinsPickedLabelC)
