#ifndef __MODEL_H__
#define __MODEL_H__

#include <SFML/Graphics.hpp>
#include <memory>
#include "display.h"

class Model {
  private:
    std::unique_ptr<Display> display;
  public:
    Model();
    Display * getDisplay();
};

#endif
