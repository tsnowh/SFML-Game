#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include <SFML/Graphics.hpp>
#include "display.h"

class Controller {
  private:
    Display display; 
  public:
    Controller();
    void Gameloop();
};

#endif
