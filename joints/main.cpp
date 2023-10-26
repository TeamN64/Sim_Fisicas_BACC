#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "articulacion de distancia");

    sf::Vector2f startPoint(200.0f, 300.0f);
    sf::Vector2f endPoint(600.0f, 300.0f);

    sf::CircleShape startCircle(10.0f);
    startCircle.setFillColor(sf::Color::Red);
    startCircle.setPosition(startPoint);

    sf::CircleShape endCircle(10.0f);
    endCircle.setFillColor(sf::Color::Blue);
    endCircle.setPosition(endPoint);

    sf::Vertex line[] = {
            sf::Vertex(startPoint, sf::Color::Green),
            sf::Vertex(endPoint, sf::Color::Green)
    };

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw(line, 2, sf::Lines);
        window.draw(startCircle);
        window.draw(endCircle);
        window.display();
    }
    return 0;
}
