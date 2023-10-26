#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "articulación de rotación");

    sf::Vector2f pivotPoint(400.0f, 300.0f);

    sf::RectangleShape arm(sf::Vector2f(200.0f, 10.0f));
    arm.setFillColor(sf::Color::Blue);
    arm.setOrigin(0, arm.getSize().y / 2);

    float angle = 0.0f;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            angle -= 1.0f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            angle += 1.0f;
        }

        arm.setRotation(angle);
        arm.setPosition(pivotPoint);

        window.clear();
        window.draw(arm);
        window.display();
    }
    return 0;
}
