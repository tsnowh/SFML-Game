#ifndef __MODEL_H__
#define __MODEL_H__

#include <SFML/Graphics.hpp>
#include <memory>

#include "display.h"
#include "player.h"

class Model {
  private:
    std::unique_ptr<Display> display;
    std::unique_ptr<Player> player;
  public:
    Model();
    Display * getDisplay();
    Player * getPlayer();
};

#endif
