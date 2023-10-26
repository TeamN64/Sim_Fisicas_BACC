#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "articulación de rueda");

    sf::Vector2f pivotPoint(400.0f, 300.0f);

    float wheelRadius = 50.0f;

    sf::CircleShape wheel(wheelRadius);
    wheel.setFillColor(sf::Color::Blue);
    wheel.setOrigin(wheelRadius, wheelRadius);
    wheel.setPosition(pivotPoint.x + 100.0f, pivotPoint.y);

    float angularSpeed = 100.0f;

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        float elapsedTime = clock.getElapsedTime().asSeconds();
        float angle = angularSpeed * elapsedTime;

        wheel.setPosition(pivotPoint.x + wheelRadius * std::cos(angle * 3.14159265 / 180),
                          pivotPoint.y + wheelRadius * std::sin(angle * 3.14159265 / 180));

        window.clear();
        window.draw(wheel);
        window.display();
    }
    return 0;
}
