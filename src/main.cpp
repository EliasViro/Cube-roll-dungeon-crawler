#include "DungeonGeneration/dungeonlevel.hpp"

#include "Characters/enemy.hpp"
#include "Characters/characterplayer.hpp"

#include "Items/meleeweapons.hpp"
#include "Items/rangedweapons.hpp"
#include "Items/shields.hpp"
#include "Items/potions.hpp"

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





//#####################################################################################################
/*
This function is called from the main() when the player clicks the start game button in the start menu.
This function holds a game loop which is active while a game instance is running. When the game ends,
the program execution returns to the main() and the player is thrown back to start menu.
*/
void room(sf::RenderWindow& window, int sidelenght) {
    // Game view items
    sf::Texture game_texture;
    game_texture.loadFromFile("../src/Graphics/GUI_Sprites/UI_PIC.png");
    sf::Sprite game_sprite(game_texture);



    sf::RectangleShape end_game_button(sf::Vector2f(115, 115));
    end_game_button.setPosition(1415, 712);

    // Game loop
    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (end_game_button.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                return;
            }

        }

        window.clear();
        window.draw(game_sprite);
        window.display();
    }

        return;
}
/*
Main game:

1. Create the player character and a pointer to it. Remember starting items.
2. Create six pre-made vectors of characters, one for each level, and divide the enemies into randomly sized 8 groups (smaller enemy vectors that will be assigned to rooms).
3. Create loot vectors of items for each level.

Loop starts from here:
1. Generate a level
2. Place the player on the level entrance tile in the starting room. Update graphics.
3. Ask for player input and move the player accordingly, or allow interacting with the inventory, open the level map etc.
4. When the player walks to a door tile, move the player to the next room, and if the size of the enemy group next in the enemy vector is larger than zero, spawn enemies and close doors. 
Update Graphics.
5. Player moves first (can't walk to inpassable tiles), graphics are updated. The top item is checked for using conditions and possibly used. Player input might be needed in case of multiple
enemies being in range of a weapon that can only target one enemy at a time. Graphics are updated again.
6. Traps cycle one step, check if the player tile trap state is Spikes and deal 1 damage if it is. If the player health is reduced to zero, play trap sound and game over. Reduce all item cooldowns.
7. Enemies move, and after all of them have moved, update graphics and play sounds, including traps. If the player health is reduced to zero, game over.
8. When all enemies have been defeated, spawn the appropriate loot item from the loot vector if the next item in it isn't a nullptr.
9. When the player enters the last room of a level, make the level exit visible.
10. When the enemies of the last room on a level are defeated, open the level exit.
11. Change the player tile to a storage tile, delete the level and resume loop from step 1.
*/





//#############################################################################################################
// This function simply loops through the six levels of one game instance.
void levelLoop(sf::RenderWindow& window) {
    
    auto const levels = {1, 2, 3, 4, 5, 6};
    int sidelength;

    for (int i : levels) {
        if (i == 1) sidelength = 2;
        else if (1 < i < 6) sidelength = 3;
        else sidelength = 4;

        DungeonLevel level(sidelength);

        //level(window, sidelength);
    }

    return;
}





//#################################################################################################################
// This is a main function that launches the game i.e. initiates a render window in which a start menu is displayed.
int main() {
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Dungeon Crawler", sf::Style::Close);
    
    // Start menu items
    sf::Texture menu_texture;
    menu_texture.loadFromFile("../src/Graphics/GUI_Sprites/MainMenu.png");
    sf::Sprite menu_sprite(menu_texture);

    sf::ConvexShape quit_button;
    quit_button.setPointCount(4);
    quit_button.setPoint(0, sf::Vector2f(500, 261));
    quit_button.setPoint(1, sf::Vector2f(782, 399));
    quit_button.setPoint(2, sf::Vector2f(782, 743));
    quit_button.setPoint(3, sf::Vector2f(500, 597));

    sf::ConvexShape start_button;
    start_button.setPointCount(4);
    start_button.setPoint(0, sf::Vector2f(820, 405));
    start_button.setPoint(1, sf::Vector2f(1100, 265));
    start_button.setPoint(2, sf::Vector2f(1100, 595));
    start_button.setPoint(3, sf::Vector2f(820, 735));

    sf::ConvexShape instructions_button;
    instructions_button.setPointCount(4);
    instructions_button.setPoint(0, sf::Vector2f(213, 233));
    instructions_button.setPoint(1, sf::Vector2f(799, 93));
    instructions_button.setPoint(2, sf::Vector2f(1085, 235));
    instructions_button.setPoint(3, sf::Vector2f(799, 375));

    /*
    sf::Music start_music;
    start_music.openFromFile("../src/Sounds/Music/Placeholder.ogg");
    */

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
      
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (quit_button.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                window.close();
            }
            else if (start_button.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                std::cout << "Start button pressed" << std::endl;
                levelLoop(window);
            }
            else if (instructions_button.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                std::cout << "Instructions button pressed" << std::endl;
            }

        }
        
        window.clear();
        window.draw(menu_sprite);
        window.display();

        //start_music.play();
    }

    return 0;
}


//A function that generates a vector of five enemies depending on the level the player is on.

std::vector<Character*> GenerateRoomEnemies(int level) {
	if (level == 1) {
		int randomnumber = rand() % 3 + 1;
		if (randomnumber == 1) {
			return {new Slime(nullptr), new Slime(nullptr), new Slime(nullptr), new Slime(nullptr), new Slime(nullptr)};
		}
		else if (randomnumber == 2) {
			return {new SmallSpider(nullptr), nullptr, new Slime(nullptr), new SmallSpider(nullptr), nullptr};
		}
		else {
			return {nullptr, new Slime(nullptr), new Slime(nullptr), new Slime(nullptr), new SmallSpider(nullptr)};
		}
	}
	else if (level == 2) {
		int randomnumber = rand() % 4 + 1;
		if (randomnumber == 1) {
			return {nullptr, nullptr, nullptr, nullptr, nullptr};
		}
		else if (randomnumber == 2) {
			return {new LargeSlime(nullptr), new SmallSpider(nullptr), new LargeSlime(nullptr), new SmallSpider(nullptr), new SmallSpider(nullptr)};
		}
		else if (randomnumber == 3) {
			return {new Spider(nullptr), new Slime(nullptr), new Slime(nullptr), new Spider(nullptr), new Spider(nullptr)};
		}
		else {
			return {new Spider(nullptr), new LargeSlime(nullptr), new Spider(nullptr), new Spider(nullptr), new Spider(nullptr)};
		}
	}
	else if (level == 3) {
		int randomnumber = rand() % 4 + 1;
		if (randomnumber == 1) {
			return {nullptr, nullptr, nullptr, nullptr, nullptr};
		}
		else if (randomnumber == 2) {
			return {new Spider(nullptr), new Spider(nullptr), new Spider(nullptr), new Spider(nullptr), new Spider(nullptr)};
		}
		else if (randomnumber == 3) {
			return {new Spider(nullptr), new HugeSlime(nullptr), new HugeSlime(nullptr), new Spider(nullptr), new Spider(nullptr)};
		}
		else {
			return {new LargeSlime(nullptr), new LargeSlime(nullptr), new LargeSlime(nullptr), new BigSpider(nullptr), new SpitterSpider(nullptr)};
		}
	}
	else if (level == 4) {
		int randomnumber = rand() % 5 + 1;
		if (randomnumber == 1) {
			return {nullptr, nullptr, nullptr, nullptr, nullptr};
		}
		else if (randomnumber == 2) {
			return {new BigSpider(nullptr), new BigSpider(nullptr), new HugeSlime(nullptr), new BigSpider(nullptr), new HugeSlime(nullptr)};
		}
		else if (randomnumber == 3) {
			return {new SpitterSpider(nullptr), new SmallSpider(nullptr), new SmallSpider(nullptr), new SpitterSpider(nullptr), new SmallSpider(nullptr)};
		}
		else if (randomnumber == 4) {
			return {new Spider(nullptr), new SpitterSpider(nullptr), new Spider(nullptr), new Spider(nullptr), nullptr};
		}
		else {
			return {new SpitterSpider(nullptr), new BigSpider(nullptr), new BigSpider(nullptr), new BigSpider(nullptr), nullptr};
		}
	}
	else if (level == 5) {
		int randomnumber = rand() % 5 + 1;
		if (randomnumber == 1) {
			return {nullptr, nullptr, nullptr, nullptr, nullptr};
		}
		else if (randomnumber == 2) {
			return {new Skeleton(nullptr), new SkeletonWarrior(nullptr), new SkeletonWarrior(nullptr), new Skeleton(nullptr), new SkeletonWarrior(nullptr)};
		}
		else if (randomnumber == 3) {
			return {new SkeletonKnight(nullptr), new Skeleton(nullptr), new Skeleton(nullptr), new SkeletonArcher(nullptr), new Skeleton(nullptr)};
		}
		else if (randomnumber == 4) {
			return {new SkeletonArcher(nullptr), new SkeletonWarrior(nullptr), new SkeletonWarrior(nullptr), new Skeleton(nullptr), new Skeleton(nullptr)};
		}
		else {
			return {new SkeletonMage(nullptr), new SkeletonWarrior(nullptr), new SkeletonKnight(nullptr), new Skeleton(nullptr), new Skeleton(nullptr)};
		}
	}
	else {
		int randomnumber = rand() % 7 + 1;
		if (randomnumber == 1) {
			return {nullptr, nullptr, nullptr, nullptr, nullptr};
		}
		else if (randomnumber == 2) {
			return {new SkeletonWarrior(nullptr), new SkeletonWarrior(nullptr), new SkeletonWarrior(nullptr), new SkeletonArcher(nullptr), new SkeletonWarrior(nullptr)};
		}
		else if (randomnumber == 3) {
			return {new SkeletonKnight(nullptr), new SkeletonMage(nullptr), new Skeleton(nullptr), new SkeletonMage(nullptr), new Skeleton(nullptr)};
		}
		else if (randomnumber == 4) {
			return {new SkeletonArcher(nullptr), new SkeletonWarrior(nullptr), new SkeletonWarrior(nullptr), new SkeletonKnight(nullptr), new SkeletonWarrior(nullptr)};
		}
		else if (randomnumber == 5) {
			return {new SkeletonKnight(nullptr), new SkeletonWarrior(nullptr), new SkeletonWarrior(nullptr), new SkeletonKnight(nullptr), new SkeletonWarrior(nullptr)};
		}
		else if (randomnumber == 6) {
			return {nullptr, nullptr, nullptr, nullptr, nullptr};
		}
		else {
			return {new SkeletonMage(nullptr), new SkeletonKnight(nullptr), new SkeletonKnight(nullptr), new SkeletonWarrior(nullptr), new SkeletonWarrior(nullptr)};
		}
	}
}


std::vector<std::vector<Item*>> CreateLoot() {
	std::vector<std::vector<Item*>> lootvector;

	//Level 1 loot: A shield and a potion
	std::vector<Item*> level1lootvector = {new RoundShield(), new HealthPotion()};

	//Level 2 loot: A melee weapon and two potions
	int randomnumber = rand() % 3 + 1;
	std::vector<Item*> level2lootvector;
	if (randomnumber == 1) {
		level2lootvector.push_back(new HandAxe());
	}
	else if (randomnumber == 2) {
		level2lootvector.push_back(new ArmingSword());
	}
	else {
		level2lootvector.push_back(new Mace());
	}
	level2lootvector.push_back(new HealthPotion());
	level2lootvector.push_back(new StaminaPotion());

	//Level 3 loot: A ranged weapon, a shield and a melee weapon
	randomnumber = rand() % 3 + 1;
	std::vector<Item*> level3lootvector;
	if (randomnumber == 1) {
		level3lootvector.push_back(new Javelin());
	}
	else if (randomnumber == 2) {
		level3lootvector.push_back(new Bolas());
	}
	else {
		level3lootvector.push_back(new Sling());
	}
	randomnumber = rand() % 3 + 1;
	level3lootvector.push_back(new HeaterShield());
	randomnumber = rand() % 3 + 1;
	if (randomnumber == 1) {
		level3lootvector.push_back(new HandAxe());
	}
	else if (randomnumber == 2) {
		level3lootvector.push_back(new ArmingSword());
	}
	else {
		level3lootvector.push_back(new Mace());
	}
	
	//Level 4 loot: A potion, a melee weapon, a potion and a shield
	std::vector<Item*> level4lootvector;
	level4lootvector.push_back(new StaminaPotion());
	randomnumber = rand() % 3 + 1;
	if (randomnumber == 1) {
		level4lootvector.push_back(new HandAxe());
	}
	else if (randomnumber == 2) {
		level4lootvector.push_back(new ArmingSword());
	}
	else {
		level4lootvector.push_back(new Mace());
	}
	level4lootvector.push_back(new HealthPotion());
	level4lootvector.push_back(new KiteShield());

	//Level 5 loot: A ranged weapon, a potion, a shield and a melee weapon
	randomnumber = rand() % 3 + 1;
	std::vector<Item*> level5lootvector;
	if (randomnumber == 1) {
		level5lootvector.push_back(new Javelin());
	}
	else if (randomnumber == 2) {
		level5lootvector.push_back(new Bolas());
	}
	else {
		level5lootvector.push_back(new Sling());
	}
	level5lootvector.push_back(new HealthPotion());
	level5lootvector.push_back(new TowerShield());
	randomnumber = rand() % 3 + 1;
	if (randomnumber == 1) {
		level5lootvector.push_back(new BattleAxe());
	}
	else if (randomnumber == 2) {
		level5lootvector.push_back(new LongSword());
	}
	else {
		level5lootvector.push_back(new WarHammer());
	}
	
	//Level 6 loot: A potion, a shield, a melee weapon and a potion.
	std::vector<Item*> level6lootvector;
	level5lootvector.push_back(new StaminaPotion());
	level5lootvector.push_back(new KiteShield());
	randomnumber = rand() % 3 + 1;
	if (randomnumber == 1) {
		level6lootvector.push_back(new BattleAxe());
	}
	else if (randomnumber == 2) {
		level6lootvector.push_back(new LongSword());
	}
	else {
		level6lootvector.push_back(new WarHammer());
	}
	level6lootvector.push_back(new HealthPotion());

	lootvector.push_back(level1lootvector);
	lootvector.push_back(level2lootvector);
	lootvector.push_back(level3lootvector);
	lootvector.push_back(level4lootvector);
	lootvector.push_back(level5lootvector);
	lootvector.push_back(level6lootvector);
	return lootvector;
}





// #################################### Old stuff ####################################################
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
   // ####################################################################################################

 