#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>


// User-specific local paths
//############################
// Go into the directory Graphcis/fonts. 
// Install the fff-forward-regular.ttf font on your local system.
// Copy the full path of the .ttf in the installation directory and save it into the following variable.
std::string fff_forward_path = "/home/atte/.local/share/fonts/Unknown Vendor/TrueType/FFF Forward/FFF_Forward_Regular.ttf";
//############################

int main() {
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Dungeon Crawler", sf::Style::Close);
    
    /*
    sf::RectangleShape quit_button(sf::Vector2f(300, 100));
    quit_button.setOrigin(quit_button.getLocalBounds().width/2, quit_button.getLocalBounds().height/2);
    quit_button.setPosition(800, 600);
    quit_button.setFillColor(sf::Color::Magenta);
    
    sf::RectangleShape start_button(sf::Vector2f(360, 120));
    start_button.setOrigin(start_button.getLocalBounds().width/2, start_button.getLocalBounds().height/2);
    start_button.setPosition(800, 300);
    start_button.setFillColor(sf::Color::Cyan);

    sf::Font pixel_font;
    pixel_font.loadFromFile(fff_forward_path);

    sf::Text quit_text("Quit", pixel_font, 30);
    quit_text.setOrigin(quit_text.getLocalBounds().width/2, quit_text.getLocalBounds().height/2 - 10);
    quit_text.setPosition(quit_button.getPosition());

    sf::Text start_text("Start game", pixel_font, 40);
    start_text.setOrigin(start_text.getLocalBounds().width/2, start_text.getLocalBounds().height/2 - 10);
    start_text.setPosition(start_button.getPosition());
    */

    sf::Texture menu_texture;
    menu_texture.loadFromFile("../src/Graphics/GUI_Sprites/MainMenu.png");
    sf::Sprite menu_sprite(menu_texture);

    sf::Music start_music;
    start_music.openFromFile("../src/Sounds/Music/Placeholder.ogg");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        /*
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (quit_button.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                window.close();
            }
            else if (start_button.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                std::cout << "Start button works" << std::endl;
            }

        }
        */

        window.clear();
        window.draw(menu_sprite);
        //window.draw(quit_button);
        //window.draw(start_button);
        //window.draw(quit_text);
        //window.draw(start_text);
        window.display();

        //start_music.play();
    }

    return 0;

}



/*
Main game:

1. Create the player character and a pointer to it. Remember starting items.
2. Create six pre-made vectors of characters, one for each level, and divide the enemies into randomly sized 8 groups (smaller enemy vectors that will be assigned to rooms).
3. Create loot vectors of items for each level.

Loop starts from here:
1. Generate a level
2. Place the player on the level entrance tile in the starting room.
3. Ask for player input and move the player accordingly.
4. When the player walks to a door tile, move the player to the next room, and if the size of the enemy group next in the enemy vector is larger than zero, spawn enemies and close doors.
5. Player moves first (can't walk to inpassable tiles), the top item is checked for using conditions and possibly used, graphics are updated. Player input might be needed in case of multiple
enemies being in range of a weapon that can only target one enemy at a time.
6. Traps cycle one step, graphics are updated, play trap sound. Then enemies move, and after all of them have moved, update graphics and play sounds.
7. When all enemies have been defeated, spawn the appropriate loot item from the loot vector if it isn't a nullptr.
8. When the enemies of the last room on a level are defeated, change player tile to a storage tile, delete the level and generate a new one. Then place the player on the level entrance and
resume loop from step 3.
*/