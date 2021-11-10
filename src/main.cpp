#include <SFML/Graphics.hpp>


int main() {
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Dungeon Crawler");
    
    sf::RectangleShape quit_button(sf::Vector2f(300, 100));
    quit_button.setOrigin(150, 50);
    quit_button.setPosition(800, 600);
    quit_button.setFillColor(sf::Color::Magenta);
    
    sf::RectangleShape start_button(sf::Vector2f(360, 120));
    start_button.setOrigin(180, 60);
    start_button.setPosition(800, 300);
    start_button.setFillColor(sf::Color::Cyan);

    sf::Font pixel_font;
    pixel_font.loadFromFile("Graphics/fonts/fff-forward-regular.ttf");

    sf::Text quit_text("Quit", pixel_font, 30);
    quit_text.setOrigin(quit_text.getLocalBounds().width/2, quit_text.getLocalBounds().height/2);
    quit_text.setPosition(quit_button.getPosition());

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(quit_button);
        window.draw(start_button);
        window.draw(quit_text);
        window.display();
    }

    return 0;

}


/*


sf::CircleShape shape(100.f);
shape.setFillColor(sf::Color::Green);

*/