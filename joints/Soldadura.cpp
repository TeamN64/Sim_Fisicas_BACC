#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "articulación de soldadura");

    sf::RectangleShape objeto1(sf::Vector2f(100.0f, 50.0f));
    objeto1.setFillColor(sf::Color::Red);
    objeto1.setPosition(300.0f, 300.0f);

    sf::RectangleShape objeto2(sf::Vector2f(150.0f, 50.0f));
    objeto2.setFillColor(sf::Color::Blue);
    objeto2.setPosition(200.0f, 300.0f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw(objeto1);
        window.draw(objeto2);
        window.display();
    }
    return 0;
}
