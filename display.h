#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include <SFML/Graphics.hpp>
#include <memory>

class Display {
  private:
    //sf::RenderWindow window; 
    std::unique_ptr<sf::RenderWindow> window;
  public:
    Display();
    sf::RenderWindow * getWindow();
};


#endif

