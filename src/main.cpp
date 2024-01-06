#include <SFML/Graphics.hpp>


enum sColor
{
    RED, GREEN, YELLOW
};

class AShape
{
    float m_sx{};                                           // speed in x direction
    float m_sy{};                                           // speed in y direction
    sf::Vector2f m_initialPosition;                         
    sColor m_color;                                         // color of the shape

public:
    sf::Shape* shape = nullptr;
    AShape(sColor color, float sx, float sy, sf::Vector2f position)
    {
        m_sx = sx;
        m_sy = sy;
        m_initialPosition = position;
        m_color = color;
    }

    void updatePosition()
    {
        shape->setPosition(shape->getPosition().x + m_sx, shape->getPosition().y + m_sy);
    }

};

class Circle : public AShape
{
    float radius;
public:
    Circle(float r, sColor color, float sx, float sy, sf::Vector2f position) :
        AShape(color, sx, sy, position),
        radius(r)
    {
        shape = new sf::CircleShape(radius);

        if (color == sColor::GREEN)
            shape->setFillColor(sf::Color::Green);
        else if (color == sColor::RED)
            shape->setFillColor(sf::Color::Red);
        else
            shape->setFillColor(sf::Color::Yellow);

        shape->setPosition(position);
    }

    /*void draw(sf::RenderWindow& w) {
        w.draw(shape->getGlobalBounds());
    }*/
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(1080, 720), "Window");
    window.setFramerateLimit(144);

    AShape* circle = new Circle(50.0f, sColor::GREEN, 0.1, 0.1, sf::Vector2f(100.0f, 100.0f));
    /*sf::CircleShape circle(50);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(sf::Vector2f(100.0f, 100.0f));
    float circleSpeed = 0.1f;*/
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed)
            {
                /*if (event.key.code == sf::Keyboard::X)
                {
                    circleSpeed = -circleSpeed;
                }*/
                if (event.key.code == sf::Keyboard::Q)
                {
                    window.close();
                }
                if (event.key.code == sf::Keyboard::C)
                {
                    sf::Image img;
                    img = window.capture();
                    img.saveToFile("TestImage.png");
                }
            }
        }
        //circle.setPosition(sf::Vector2f(circle.getPosition().x + circleSpeed, circle.getPosition().y + circleSpeed));
        circle->updatePosition();
        window.clear();
        window.draw(*(circle->shape));
        window.display();
    }
}