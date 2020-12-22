#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include <SFML/Graphics.hpp>
#include <memory>

class Display {
  private:
    //sf::RenderWindow window; 
    sf::RenderWindow window;
  public:
    Display(unsigned int width = 500, unsigned int height = 500);
    sf::RenderWindow& getWindow();
};


#endif

