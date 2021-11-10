#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "DungeonGeneration/dungeontile.hpp"

int main() {
    DungeonTile joku = DungeonTile(true, Floor, 1, 1);
    std::out<<joku.IsPassable();
    std::cout << "Hello world!" << std::endl;
    std::cout << str << std::endl;

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;

}