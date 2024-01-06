#ifndef SHAPES_H
#define SHAPES_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "utils.h"

class AShape
{
    float m_sx{};                                           // speed in x direction
    float m_sy{};                                           // speed in y direction
    sf::Vector2f m_initialPosition;
    sColor m_color;

public:
    sf::Shape* shape = nullptr;
    AShape(sColor color, float sx, float sy, sf::Vector2f position);
    void updatePosition();
    void initializeShape();
    ~AShape();
};

class Circle : public AShape
{
    float radius;
public:
    Circle(float r, sColor color, float sx, float sy, sf::Vector2f position);
};

class Rectangle : public AShape
{
    float width, height;
public:
    Rectangle(float w, float h, sColor color, float sx, float sy, sf::Vector2f position);
};

#endif // !SHAPES_H