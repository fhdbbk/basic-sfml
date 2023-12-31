#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1080, 720), "Window");
    window.setFramerateLimit(144);

    sf::CircleShape circle(50);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(sf::Vector2f(100.0f, 100.0f));
    float circleSpeed = 0.1f;
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
                if (event.key.code == sf::Keyboard::X)
                {
                    circleSpeed = -circleSpeed;
                }
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
        circle.setPosition(sf::Vector2f(circle.getPosition().x + circleSpeed, circle.getPosition().y + circleSpeed));
        window.clear();
        window.draw(circle);
        window.display();
    }
}