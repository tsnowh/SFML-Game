#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include <SFML/Graphics.hpp>
#include "model.h"

class Controller {
  private:
    Model model;
    int width;
    int height;

    //handlers
    void KeyPressedHandler();
  public:
    Controller(int width, int height);
    void Gameloop();
};

#endif
