#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include <SFML/Graphics.hpp>
#include <memory>

class Model;

class Display {
  private:
    //sf::RenderWindow window; 
    sf::RenderWindow window;
    
    sf::RectangleShape healthBar;
    float healthWidth;
    float healthHeight;
    float bufferWidth = 10;
    float bufferHeight = 10;
    Model *model;
  public:
    Display(Model *, unsigned int width = 500, unsigned int height = 500);
    sf::RenderWindow& getWindow();
    void renderHealthBar();
};


#endif

