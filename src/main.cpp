#include "shapes.h"
#include <memory>

int main()
{
    std::cout << "Starting code\n";
    sf::RenderWindow window(sf::VideoMode(1080, 720), "Window");
    window.setFramerateLimit(144);

    std::vector<std::shared_ptr<AShape>> myShapes;

    //AShape* circle = new Circle(50.0f, sColor::YELLOW, 0.1, 0.1, sf::Vector2f(100.0f, 100.0f));
    //AShape* rectangle = new Rectangle(150, 300, sColor::RED, -0.2, 0.3, sf::Vector2(700.0f, 50.0f));

    std::shared_ptr<AShape> circle = std::make_shared<Circle>(50.0f, sColor::YELLOW, 0.1, 0.1, sf::Vector2f(100.0f, 100.0f));
    std::shared_ptr<AShape> rectangle = std::make_shared<Rectangle>(150, 300, sColor::RED, -0.2, 0.3, sf::Vector2(700.0f, 50.0f));

    myShapes.push_back(circle);
    myShapes.push_back(rectangle);
    
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
        for (auto& shape : myShapes)
        {
            shape->updatePosition();
        }
        //circle->updatePosition();
        //rectangle->updatePosition();
        window.clear();
        for (auto& shape : myShapes)
        {
            window.draw(*(shape->shape));
        }
        //window.draw(*(circle->shape));
        //window.draw(*(rectangle->shape));
        window.display();
    }

    //delete circle;
    //delete rectangle;
}