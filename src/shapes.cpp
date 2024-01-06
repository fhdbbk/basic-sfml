#include "shapes.h"

AShape::AShape(sColor color, float sx, float sy, sf::Vector2f position)
{
    m_sx = sx;
    m_sy = sy;
    m_initialPosition = position;
    m_color = color;
}

void AShape::initializeShape()
{
    if (m_color == sColor::GREEN)
        shape->setFillColor(sf::Color::Green);
    else if (m_color == sColor::RED)
        shape->setFillColor(sf::Color::Red);
    else
        shape->setFillColor(sf::Color::Yellow);

    shape->setPosition(m_initialPosition);
}

void AShape::updatePosition()
{
    shape->setPosition(shape->getPosition().x + m_sx, shape->getPosition().y + m_sy);
}

AShape::~AShape()
{
    std::cout << "Destructor for Ashape called\n";
    delete shape;
}

Circle::Circle(float r, sColor color, float sx, float sy, sf::Vector2f position) :
    AShape(color, sx, sy, position),
    radius(r)
{
    shape = new sf::CircleShape(radius);
    initializeShape();
}

Rectangle::Rectangle(float w, float h, sColor color, float sx, float sy, sf::Vector2f position) :
    AShape(color, sx, sy, position), width(w), height(h)
{
    shape = new sf::RectangleShape(sf::Vector2f(width, height));
    initializeShape();
}