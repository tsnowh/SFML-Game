#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include <SFML/Graphics.hpp>
#include <memory>

class Display {
  private:
    //sf::RenderWindow window; 
    sf::RenderWindow window;
  public:
    Display();
    sf::RenderWindow& getWindow();
};


#endif

