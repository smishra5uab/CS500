#ifndef screenSaver_h
#define screenSaver_h

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

//The Parent Class!
class ScreenSaver {
private:
  //this is the object that will be drawn on the screen
  //IMPORTANT: check out the documentation for sf::CircleShape in order to understand how to use this.
  sf::CircleShape shape;

public:
  //Constructors
  ScreenSaver();
  ScreenSaver(float radius, sf::Vector2f cVelocity, sf::Color color);
  
  //public member variable
  sf::Vector2f velocity;

  //Getter for shape
  sf::CircleShape &getShape();

  //nifty function, see screenSaver.cpp for more details
  void checkWallCollision(int screenWidth, int screenHeight);

  /*This is the most important function!
      It is a pure virtual function, meaning that it MUST be overriden by child classes
      Every child class will have it's own definition for this function*/
  virtual void update(float deltaTime, int screenWidth, int screenHeight) = 0;
  
  //See screenSaver.cpp for details
  void draw(sf::RenderWindow &window);

  //All parent classes should have a deconstructor, even if it is empty
  virtual ~ScreenSaver() {} 
};

class ClassicSaver : public ScreenSaver {
public:
    ClassicSaver(float radius, sf::Vector2f velocity, sf::Color color);

    // Override the update function
    void update(float deltaTime, int screenWidth, int screenHeight);
};

// The ColorChanging saver shall change color of the circle randomly over time
class ColorChangingSaver : public ClassicSaver {
private:
    float colorSpeed;

public:
    ColorChangingSaver(float radius, sf::Vector2f velocity, float colorSpeed);

    void update(float deltaTime, int screenWidth, int screenHeight);
};

// The CustomSaver shall change the color of the circle on collision against walls and also change
// size of the circle smoothly
class CustomSaver : public ScreenSaver {
public:
    CustomSaver(float radius, sf::Vector2f velocity, float sizeChangeSpeed);

    void update(float deltaTime, int screenWidth, int screenHeight);

private:
    float sizeChangeSpeed;
};

#endif
