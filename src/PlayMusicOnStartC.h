#pragma once

#include "Component.h"
#include "Factory.h"

#include <string>

// FACTORY INFRASTRUCTURE DECLARATION
DECLARE_FACTORY(PlayMusicOnStartC);

class PlayMusicOnStartC : public Component {
  private:
    std::string music = "";

  public:
    PlayMusicOnStartC() = default;
    virtual ~PlayMusicOnStartC() = default;

    virtual void destroy();

    void setMusic(std::string sound);
};
