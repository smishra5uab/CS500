#include "screenSaver.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <cmath>
#include<cstdlib>

//Self-explanatory
ScreenSaver::ScreenSaver() {
  shape = sf::CircleShape(10.f);
  velocity = sf::Vector2f(0.0f, 0.0f);
  shape.setFillColor(sf::Color::White);
}

//Self-explanatory
ScreenSaver::ScreenSaver(float radius, sf::Vector2f cVelocity, sf::Color color) {
  shape = sf::CircleShape(radius);
  velocity = cVelocity;
  shape.setFillColor(color);
}

//We have to return shape as a reference!
sf::CircleShape &ScreenSaver::getShape() { return shape; }

//this will draw the sf::CircleShape member of ScreenSaver to the screen
//this will be inherited by all derived class, and shouldn't have to be overriden
void ScreenSaver::draw(sf::RenderWindow &window) { window.draw(getShape()); }

/*Here's some nifty code to resolve any collsions with a wall, by reversing
the velocity of the object to mimic bouncing, you can call this function
in your update functions to make sure your ScreenSaver doesn't wander off-screen*/
void ScreenSaver::checkWallCollision(int screenWidth, int screenHeight){
  sf::Vector2f position = getShape().getPosition();
  float diameter = getShape().getRadius() * 2;

  // Check if the circle hits the right wall
  if (position.x + diameter > screenWidth)
  {
    getShape().setPosition(screenWidth - diameter, position.y);
    velocity.x *= -1.f;
  }

  // Check if the circle hits the left wall
  if (position.x < 0)
  {
    getShape().setPosition(0, position.y);
    velocity.x *= -1.f;
  }

  // Check if the circle hits the top wall
  if (position.y < 0)
  {
    getShape().setPosition(position.x, 0);
    velocity.y *= -1.f;
  }

  // Check if the circle hits the bottom wall
  if (position.y + diameter > screenHeight)
  {
    getShape().setPosition(position.x, screenHeight - diameter);
    velocity.y *= -1.f;
  }
}

// Implementation of ClassicSaver
ClassicSaver::ClassicSaver(float radius, sf::Vector2f velocity, sf::Color color)
  : ScreenSaver(radius, velocity, color) {}

// This shall fulfill the basic implementation of a classic saver
void ClassicSaver::update(float deltaTime, int screenWidth, int screenHeight) {
    getShape().move(velocity * deltaTime);

    checkWallCollision(screenWidth, screenHeight);
}

// Implementation of ColorChangingSaver
ColorChangingSaver::ColorChangingSaver(float radius, sf::Vector2f velocity, float colorSpeed)
  : ClassicSaver(radius, velocity, sf::Color::Red), colorSpeed(colorSpeed) {}

// Here the classicSaver is called and updated such that it changes to a random color with time
void ColorChangingSaver::update(float deltaTime, int screenWidth, int screenHeight) {
    // Call ClassicSaver's update for movement and wall bouncing
    ClassicSaver::update(deltaTime, screenWidth, screenHeight);

    // Initialize static variables to track time and current color index
    static float timeChanger = 0.0f;

    timeChanger += deltaTime * colorSpeed * 0.1f;

    // set to a random color on time change reaching the limit and then update the timechanger to 0
    if (timeChanger >= 10.0f) {
        timeChanger = 0.0f;
        getShape().setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
    }
}

// Implementation of CustomSaver
CustomSaver::CustomSaver(float radius, sf::Vector2f velocity, float sizeChangeSpeed)
  : ScreenSaver(radius, velocity, sf::Color::White), sizeChangeSpeed(sizeChangeSpeed) {}

// The CustomSaver changes to a random color each time the circle collides with a wall and 
// also shrinks and grows with time
void CustomSaver::update(float deltaTime, int screenWidth, int screenHeight) {
    getShape().move(velocity * deltaTime);

    checkWallCollision(screenWidth, screenHeight);

    if (getShape().getPosition().x <= 0 ||
        getShape().getPosition().x >= screenWidth - getShape().getRadius() * 2 ||
        getShape().getPosition().y <= 0 ||
        getShape().getPosition().y >= screenHeight - getShape().getRadius() * 2) {
        getShape().setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
    }

    float currentSize = getShape().getRadius();
    float newSize;
    bool increasing = true;

    if (increasing) {
        newSize = currentSize + sizeChangeSpeed * deltaTime * 0.1f;
        if (newSize >= 100.0f) {
            newSize = 100.0f;
            increasing = false;
        }
    } else {
        newSize = currentSize - sizeChangeSpeed * deltaTime * 0.1f;
        if (newSize <= 10.0f) {
            newSize = 10.0f;
            increasing = true;
        }
    }

    getShape().setRadius(newSize);
}