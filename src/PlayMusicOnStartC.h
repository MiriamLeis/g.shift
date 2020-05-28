#pragma once

#include "Component.h"
#include "Factory.h"

#include <string>

// FACTORY INFRASTRUCTURE DECLARATION
DECLARE_FACTORY(PlayMusicOnStartC)

class PlayMusicOnStartC final : public Component {
    std::string music_ = "";

  public:
    void destroy() override;
    void setMusic(const std::string& sound);
    void stopCurrentMusic(const std::string& sound);
};
