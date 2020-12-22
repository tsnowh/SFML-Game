#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include <SFML/Graphics.hpp>
#include "model.h"

class Controller {
  private:
    Model model;

    //handlers
    void KeyPressedHandler(sf::Event &e);
  public:
    Controller();
    void Gameloop();
};

#endif
