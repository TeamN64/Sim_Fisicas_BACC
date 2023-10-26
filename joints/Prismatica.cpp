#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "articulación prismática");

    sf::RectangleShape object(sf::Vector2f(50.0f, 30.0f));
    object.setFillColor(sf::Color::Blue);
    object.setPosition(375.0f, 300.0f);

    float velocity = 5.0f;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            object.move(-velocity, 0.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            object.move(velocity, 0.0f);
        }

        window.clear();
        window.draw(object);
        window.display();
    }
    return 0;
}
