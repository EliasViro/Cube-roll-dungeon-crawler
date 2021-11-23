
// C++ standard libraries
#include <iostream>
#include <vector>

// SFML
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

// Project
#include "DungeonGeneration/dungeonlevel.hpp"
#include "DungeonGeneration/dungeonroom.hpp"
#include "DungeonGeneration/dungeontile.hpp"

#include "Characters/enemy.hpp"
#include "Characters/characterplayer.hpp"

#include "Items/meleeweapons.hpp"
#include "Items/rangedweapons.hpp"
#include "Items/shields.hpp"
#include "Items/potions.hpp"

#include "Graphics/spritecontainer.hpp"


// User-specific local paths
//############################
// Go into the directory Graphcis/fonts. 
// Install the fff-forward-regular.ttf font on your local system.
// Copy the full path of the .ttf in the installation directory and save it into the following variable.
std::string fff_forward_path = "/home/atte/.local/share/fonts/Unknown Vendor/TrueType/FFF Forward/FFF_Forward_Regular.ttf";
//############################

// Global variables
const int gameboard_orig_x = 65;
const int gameboard_orig_y = 67;

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


<<<<<<< HEAD
    //Create all sprites

    int x_orig = 65;
    int y_orig = 67;

    for (auto enemy : enemyvec) {
		if (enemy != nullptr) {
			int xcoord = enemy->GetXCoordinate();
			int ycoord = enemy->GetYCoordinate();
			int x = x_orig + (xcoord - 1) * 64;
			int y = y_orig + (ycoord - 1) * 64;
			ActionType currentaction = enemy->GetCurrentAction();
			EnemyAI currentAI = enemy->GetEnemyAI();

			//Draw the basic black enemy sprite here, the rest is drawn on top of it.

			if (currentaction == Melee_1) {
				//Draw the sword
			}
			else if (currentaction == Melee_2) {
				//Draw the warhammer
			}
			else if (currentaction == Melee_3) {
				//Draw the axe
			}
			else if (currentaction == Ranged_1) {
				//Draw the smallest bow
			}
			else if (currentaction == Ranged_2) {
				//Draw the medium sized bow
			}
			else if (currentaction == Ranged_3) {
				//Draw the largest bow
			}
			else if (currentaction == Defend_1) {
				//Draw the shield with number 1
			}
			else if (currentaction == Defend_2) {
				//Draw the shield with number 2
			}
			else if (currentaction == Defend_3) {
				//Draw the shield with number 3
			}
			else {
				//Draw the empty enemy sprite (has zero at top right corner)
			}

			if (enemy->IsStunned()) {
				//Draw the Stunned AI symbol
			}
			else if (currentAI == Aggressive) {
				//Draw the Aggressive AI symbol
			}
			else if (currentAI == Careful) {
				//Draw the Careful AI symbol
			}
			else if (currentAI == Random) {
				//Draw the Random AI symbol
			}
			else {
				//Draw the Boss AI symbol
			}
		}
    }
}
=======
// This function draws a new room in its initial state.
void RenderScreen(sf::RenderWindow& window, std::vector<std::vector<DungeonTile*>> tile_matrix, bool islastroominlevel, std::vector<Character*> enemyvec, Character* player) {
>>>>>>> 133d0f772ba7415e56d9b163f6a4cf35636ce3c2

	//FIRST, CLEAR WINDOW, THEN DRAW UI SPRITE

	// Create all sprites
	sf::Texture door_closed_t;
	door_closed_t.loadFromFile("../src/Graphics/TileSprites/DoorClosed.png");
	sf::Sprite sprite_door_closed(door_closed_t);

	sf::Texture floor_t;
	floor_t.loadFromFile("../src/Graphics/TileSprites/Floor.png");
	sf::Sprite sprite_floor(floor_t);

	sf::Texture levelexitclosed_t;
	levelexitclosed_t.loadFromFile("../src/Graphics/TileSprites/LevelExitClosed.png");
	sf::Sprite sprite_levelexitclosed(levelexitclosed_t);

	sf::Texture pit_t;
	pit_t.loadFromFile("../src/Graphics/TileSprites/Pit.png");
	sf::Sprite sprite_pit(pit_t);

	sf::Texture trap1_t;
	trap1_t.loadFromFile("../src/Graphics/TileSprites/Trap1.png");
	sf::Sprite sprite_trap1(trap1_t);

	sf::Texture trap2_t;
	trap2_t.loadFromFile("../src/Graphics/TileSprites/Trap2.png");
	sf::Sprite sprite_trap2(trap2_t);

	sf::Texture trap3_t;
	trap3_t.loadFromFile("../src/Graphics/TileSprites/Trap3.png");
	sf::Sprite sprite_trap3(trap3_t);

	sf::Texture wall_t;
	wall_t.loadFromFile("../src/Graphics/TileSprites/Wall.png");
	sf::Sprite sprite_wall(wall_t);

	int x_orig = 65;
	int y_orig = 67;
	
	for (std::vector<DungeonTile*> i : tile_matrix) {
		for (DungeonTile* tile : i) {
			int i_coord = tile->GetYCoord();
			int j_coord = tile->GetXCoord();
			std::cout << "i: " << i_coord << ", j: " << j_coord << std::endl;
			int x = x_orig + (j_coord)*64;
			int y = y_orig + (i_coord)*64;

			TileType tiletype = tile->GetTileType();
			if (tiletype == Floor || tiletype == Spawner || tiletype == Entrance || tiletype == Loot) {
				sprite_floor.setPosition(static_cast<float>(x), static_cast<float>(y));
				window.draw(sprite_floor);
			}
			else if (tiletype == Wall) {
				sprite_wall.setPosition(static_cast<float>(x), static_cast<float>(y));
				window.draw(sprite_wall);
			}
			else if (tiletype == Pit) {
				sprite_pit.setPosition(static_cast<float>(x), static_cast<float>(y));
				window.draw(sprite_pit);
			}
			else if (tiletype == Door) {
				if (!tile->IsOpen()) {
					sprite_door_closed.setPosition(static_cast<float>(x), static_cast<float>(y));
					window.draw(sprite_door_closed);
				}
				else {
					sprite_floor.setPosition(static_cast<float>(x), static_cast<float>(y));
					window.draw(sprite_floor);
				}
			}
			else if (tiletype == Trap) {
				if (tile->GetTrapState() == Dormant) {
					sprite_trap1.setPosition(static_cast<float>(x), static_cast<float>(y));
					window.draw(sprite_trap1);
				}
				else if (tile->GetTrapState() == Emerging) {
					sprite_trap2.setPosition(static_cast<float>(x), static_cast<float>(y));
					window.draw(sprite_trap2);
				}
				else {
					sprite_trap3.setPosition(static_cast<float>(x), static_cast<float>(y));
					window.draw(sprite_trap3);
				}
			}
			else if (tiletype == Exit) {
				if (islastroominlevel) {
					if (!tile->IsOpen()) {
						sprite_levelexitclosed.setPosition(static_cast<float>(x), static_cast<float>(y));
						window.draw(sprite_levelexitclosed);
					}
					else {
						sprite_levelexitopen.setPosition(static_cast<float>(x), static_cast<float>(y));
						window.draw(sprite_levelexitopen);
					}
				}
				else {
					sprite_floor.setPosition(static_cast<float>(x), static_cast<float>(y));
					window.draw(sprite_floor);
				}
			}
			if (tile->GetItem() != nullptr) {
				auto item = tile->GetItem();
				if (item->GetName() == "Potion of healing") {
					//Draw a health potion on the tile
				}
				else if (item->GetName() == "Potion of stamina") {
					//Draw a stamina potion on the tile
				}
				else if (item->GetName() == "Javelin") {
					//Draw a javelin on the tile
				}
				else if (item->GetName() == "Bolas") {
					//Draw bolas on the tile
				}
				else if (item->GetName() == "Sling") {
					//Draw a sling on the tile
				}
				else if (item->GetName() == "Round shield") {
					//Draw a round shield on the tile
				}
				else if (item->GetName() == "Heater shield") {
					//Draw a heater shield on the tile
				}
				else if (item->GetName() == "Kite shield") {
					//Draw a kite shield on the tile
				}
				else if (item->GetName() == "Tower shield") {
					//Draw a tower shield on the tile
				}
				else if (item->GetName() == "Shortsword") {
					//Draw a shortsword on the tile
				}
				else if (item->GetName() == "Arming sword") {
					//Draw an arming sword on the tile
				}
				else if (item->GetName() == "Longsword") {
					//Draw a longsword on the tile
				}
				else if (item->GetName() == "Hatchet") {
					//Draw a hatchet on the tile
				}
				else if (item->GetName() == "Battleaxe") {
					//Draw a battleaxe on the tile
				}
				else if (item->GetName() == "Mace") {
					//Draw a mace on the tile
				}
				else if (item->GetName() == "Warhammer") {
					//Draw a warhammer on the tile
				}
			}
		}
	}
    for (auto enemy : enemyvec) {
		if (enemy != nullptr) {
			int xcoord = enemy->GetXCoordinate();
			int ycoord = enemy->GetYCoordinate();
			int x = x_orig + (xcoord - 1) * 64;
			int x = x_orig + (ycoord - 1) * 64;
			ActionType currentaction = enemy->GetCurrentAction();
			EnemyAI currentAI = enemy->GetEnemyAI();
			//Draw the basic black enemy sprite here, the rest is drawn on top of it.
			if (currentaction == Melee_1) {
				//Draw the sword
			}
			else if (currentaction == Melee_2) {
				//Draw the warhammer
			}
			else if (currentaction == Melee_3) {
				//Draw the axe
			}
			else if (currentaction == Ranged_1) {
				//Draw the smallest bow
			}
			else if (currentaction == Ranged_2) {
				//Draw the medium sized bow
			}
			else if (currentaction == Ranged_3) {
				//Draw the largest bow
			}
			else if (currentaction == Defend_1) {
				//Draw the shield with number 1
			}
			else if (currentaction == Defend_2) {
				//Draw the shield with number 2
			}
			else if (currentaction == Defend_3) {
				//Draw the shield with number 3
			}
			else {
				//Draw the empty enemy sprite (has zero at top right corner)
			}

			if (enemy->IsStunned()) {
				//Draw the Stunned AI symbol
			}
			else if (currentAI == Aggressive) {
				//Draw the Aggressive AI symbol
			}
			else if (currentAI == Careful) {
				//Draw the Careful AI symbol
			}
			else if (currentAI == Random) {
				//Draw the Random AI symbol
			}
			else {
				//Draw the Boss AI symbol
			}
		}
	}
	int playerxcoord = player->GetXCoordinate();
	int playerycoord = player->GetYCoordinate();
	auto inventory = player->GetInventory();
	//Draw the player character
	if (!inventory[0]->IsEmpty()) {
		auto invitem = inventory[0]->GetItem();
		if (invitem->GetName() == "Potion of healing") {
			//Draw a health potion on the player and in the middle inventory slot
		}
		else if (invitem->GetName() == "Potion of stamina") {
			//Draw a stamina potion on the player and in the middle inventory slot
		}
		else if (invitem->GetName() == "Javelin") {
			//Draw a javelin on the player and in the middle inventory slot
		}
		else if (invitem->GetName() == "Bolas") {
			//Draw bolas on the player and in the middle inventory slot
		}
		else if (invitem->GetName() == "Sling") {
			//Draw a sling on the player and in the middle inventory slot
		}
		else if (invitem->GetName() == "Round shield") {
			//Draw a round shield on the player and in the middle inventory slot
		}
		else if (invitem->GetName() == "Heater shield") {
			//Draw a heater shield on the player and in the middle inventory slot
		}
		else if (invitem->GetName() == "Kite shield") {
			//Draw a kite shield on the player and in the middle inventory slot
		}
		else if (invitem->GetName() == "Tower shield") {
			//Draw a tower shield on the player and in the middle inventory slot
		}
		else if (invitem->GetName() == "Shortsword") {
			//Draw a shortsword on the player and in the middle inventory slot
		}
		else if (invitem->GetName() == "Arming sword") {
			//Draw an arming sword on the player and in the middle inventory slot
		}
		else if (invitem->GetName() == "Longsword") {
			//Draw a longsword on the player and in the middle inventory slot
		}
		else if (invitem->GetName() == "Hatchet") {
			//Draw a hatchet on the player and in the middle inventory slot
		}
		else if (invitem->GetName() == "Battleaxe") {
			//Draw a battleaxe on the player and in the middle inventory slot
		}
		else if (invitem->GetName() == "Mace") {
			//Draw a mace on the player and in the middle inventory slot
		}
		else if (invitem->GetName() == "Warhammer") {
			//Draw a warhammer on the player and in the middle inventory slot
		}
	}
	if (!inventory[1]->IsEmpty()) {
		auto itemnorth = inventory[2]->GetItem();
		if (itemnorth->GetName() == "Potion of healing") {
			//Draw a health potion in the north inventory slot
		}
		else if (itemnorth->GetName() == "Potion of stamina") {
			//Draw a stamina potion in the north inventory slot
		}
		else if (itemnorth->GetName() == "Javelin") {
			//Draw a javelin in the north inventory slot
		}
		else if (itemnorth->GetName() == "Bolas") {
			//Draw bolas in the north inventory slot
		}
		else if (itemnorth->GetName() == "Sling") {
			//Draw a sling in the north inventory slot
		}
		else if (itemnorth->GetName() == "Round shield") {
			//Draw a round shield in the north inventory slot
		}
		else if (itemnorth->GetName() == "Heater shield") {
			//Draw a heater shield in the north inventory slot
		}
		else if (itemnorth->GetName() == "Kite shield") {
			//Draw a kite shield in the north inventory slot
		}
		else if (itemnorth->GetName() == "Tower shield") {
			//Draw a tower shield in the north inventory slot
		}
		else if (itemnorth->GetName() == "Shortsword") {
			//Draw a shortsword in the north inventory slot
		}
		else if (itemnorth->GetName() == "Arming sword") {
			//Draw an arming sword in the north inventory slot
		}
		else if (itemnorth->GetName() == "Longsword") {
			//Draw a longsword in the north inventory slot
		}
		else if (itemnorth->GetName() == "Hatchet") {
			//Draw a hatchet in the north inventory slot
		}
		else if (itemnorth->GetName() == "Battleaxe") {
			//Draw a battleaxe in the north inventory slot
		}
		else if (itemnorth->GetName() == "Mace") {
			//Draw a mace in the north inventory slot
		}
		else if (itemnorth->GetName() == "Warhammer") {
			//Draw a warhammer in the east inventory slot
		}
	}
	if (!inventory[2]->IsEmpty()) {
		auto itemeast = inventory[2]->GetItem();
		if (itemeast->GetName() == "Potion of healing") {
			//Draw a health potion in the east inventory slot
		}
		else if (itemeast->GetName() == "Potion of stamina") {
			//Draw a stamina potion in the east inventory slot
		}
		else if (itemeast->GetName() == "Javelin") {
			//Draw a javelin in the east inventory slot
		}
		else if (itemeast->GetName() == "Bolas") {
			//Draw bolas in the east inventory slot
		}
		else if (itemeast->GetName() == "Sling") {
			//Draw a sling in the east inventory slot
		}
		else if (itemeast->GetName() == "Round shield") {
			//Draw a round shield in the east inventory slot
		}
		else if (itemeast->GetName() == "Heater shield") {
			//Draw a heater shield in the east inventory slot
		}
		else if (itemeast->GetName() == "Kite shield") {
			//Draw a kite shield in the east inventory slot
		}
		else if (itemeast->GetName() == "Tower shield") {
			//Draw a tower shield in the east inventory slot
		}
		else if (itemeast->GetName() == "Shortsword") {
			//Draw a shortsword in the east inventory slot
		}
		else if (itemeast->GetName() == "Arming sword") {
			//Draw an arming sword in the east inventory slot
		}
		else if (itemeast->GetName() == "Longsword") {
			//Draw a longsword in the east inventory slot
		}
		else if (itemeast->GetName() == "Hatchet") {
			//Draw a hatchet in the east inventory slot
		}
		else if (itemeast->GetName() == "Battleaxe") {
			//Draw a battleaxe in the east inventory slot
		}
		else if (itemeast->GetName() == "Mace") {
			//Draw a mace in the east inventory slot
		}
		else if (itemeast->GetName() == "Warhammer") {
			//Draw a warhammer in the east inventory slot
		}
	}
	if (!inventory[3]->IsEmpty()) {
		auto itemwest = inventory[3]->GetItem();
		if (itemwest->GetName() == "Potion of healing") {
			//Draw a health potion in the west inventory slot
		}
		else if (itemwest->GetName() == "Potion of stamina") {
			//Draw a stamina potion in the west inventory slot
		}
		else if (itemwest->GetName() == "Javelin") {
			//Draw a javelin in the west inventory slot
		}
		else if (itemwest->GetName() == "Bolas") {
			//Draw bolas in the west inventory slot
		}
		else if (itemwest->GetName() == "Sling") {
			//Draw a sling in the west inventory slot
		}
		else if (itemwest->GetName() == "Round shield") {
			//Draw a round shield in the west inventory slot
		}
		else if (itemwest->GetName() == "Heater shield") {
			//Draw a heater shield in the west inventory slot
		}
		else if (itemwest->GetName() == "Kite shield") {
			//Draw a kite shield in the west inventory slot
		}
		else if (itemwest->GetName() == "Tower shield") {
			//Draw a tower shield in the west inventory slot
		}
		else if (itemwest->GetName() == "Shortsword") {
			//Draw a shortsword in the west inventory slot
		}
		else if (itemwest->GetName() == "Arming sword") {
			//Draw an arming sword in the west inventory slot
		}
		else if (itemwest->GetName() == "Longsword") {
			//Draw a longsword in the west inventory slot
		}
		else if (itemwest->GetName() == "Hatchet") {
			//Draw a hatchet in the west inventory slot
		}
		else if (itemwest->GetName() == "Battleaxe") {
			//Draw a battleaxe in the west inventory slot
		}
		else if (itemwest->GetName() == "Mace") {
			//Draw a mace in the west inventory slot
		}
		else if (itemwest->GetName() == "Warhammer") {
			//Draw a warhammer in the west inventory slot
		}
	}
	if (!inventory[4]->IsEmpty()) {
		auto itemsouth = inventory[4]->GetItem();
		if (itemsouth->GetName() == "Potion of healing") {
			//Draw a health potion in the south inventory slot
		}
		else if (itemsouth->GetName() == "Potion of stamina") {
			//Draw a stamina potion in the south inventory slot
		}
		else if (itemsouth->GetName() == "Javelin") {
			//Draw a javelin in the south inventory slot
		}
		else if (itemsouth->GetName() == "Bolas") {
			//Draw bolas in the south inventory slot
		}
		else if (itemsouth->GetName() == "Sling") {
			//Draw a sling in the south inventory slot
		}
		else if (itemsouth->GetName() == "Round shield") {
			//Draw a round shield in the south inventory slot
		}
		else if (itemsouth->GetName() == "Heater shield") {
			//Draw a heater shield in the south inventory slot
		}
		else if (itemsouth->GetName() == "Kite shield") {
			//Draw a kite shield in the south inventory slot
		}
		else if (itemsouth->GetName() == "Tower shield") {
			//Draw a tower shield in the south inventory slot
		}
		else if (itemsouth->GetName() == "Shortsword") {
			//Draw a shortsword in the south inventory slot
		}
		else if (itemsouth->GetName() == "Arming sword") {
			//Draw an arming sword in the south inventory slot
		}
		else if (itemsouth->GetName() == "Longsword") {
			//Draw a longsword in the south inventory slot
		}
		else if (itemsouth->GetName() == "Hatchet") {
			//Draw a hatchet in the south inventory slot
		}
		else if (itemsouth->GetName() == "Battleaxe") {
			//Draw a battleaxe in the south inventory slot
		}
		else if (itemsouth->GetName() == "Mace") {
			//Draw a mace in the south inventory slot
		}
		else if (itemsouth->GetName() == "Warhammer") {
			//Draw a warhammer in the south inventory slot
		}
	}
	if (!inventory[5]->IsEmpty()) {
		auto itembottom = inventory[5]->GetItem();
		if (itembottom->GetName() == "Potion of healing") {
			//Draw a health potion in the bottom inventory slot
		}
		else if (itembottom->GetName() == "Potion of stamina") {
			//Draw a stamina potion in the bottom inventory slot
		}
		else if (itembottom->GetName() == "Javelin") {
			//Draw a javelin in the bottom inventory slot
		}
		else if (itembottom->GetName() == "Bolas") {
			//Draw bolas in the bottom inventory slot
		}
		else if (itembottom->GetName() == "Sling") {
			//Draw a sling in the bottom inventory slot
		}
		else if (itembottom->GetName() == "Round shield") {
			//Draw a round shield in the bottom inventory slot
		}
		else if (itembottom->GetName() == "Heater shield") {
			//Draw a heater shield in the bottom inventory slot
		}
		else if (itembottom->GetName() == "Kite shield") {
			//Draw a kite shield in the bottom inventory slot
		}
		else if (itembottom->GetName() == "Tower shield") {
			//Draw a tower shield in the bottom inventory slot
		}
		else if (itembottom->GetName() == "Shortsword") {
			//Draw a shortsword in the bottom inventory slot
		}
		else if (itembottom->GetName() == "Arming sword") {
			//Draw an arming sword in the bottom inventory slot
		}
		else if (itembottom->GetName() == "Longsword") {
			//Draw a longsword in the bottom inventory slot
		}
		else if (itembottom->GetName() == "Hatchet") {
			//Draw a hatchet in the bottom inventory slot
		}
		else if (itembottom->GetName() == "Battleaxe") {
			//Draw a battleaxe in the bottom inventory slot
		}
		else if (itembottom->GetName() == "Mace") {
			//Draw a mace in the bottom inventory slot
		}
		else if (itembottom->GetName() == "Warhammer") {
			//Draw a warhammer in the bottom inventory slot
		}
	}
	window.display();
}





//#####################################################################################################
/*
This function holds a game loop for one room in a dungeon.
*/
bool Level(sf::RenderWindow& window, DungeonLevel level) {
	std::cout << "levelissä ollaan" << std::endl;

	std::vector<std::vector<DungeonRoom*>> rooms = level.GetRooms();
	DungeonRoom* starting_room = rooms[level.GetStartPos().first][level.GetStartPos().second];
	RenderRoom(window, starting_room);

	return false;
}





//#############################################################################################################
// This function loops through the six levels of one game instance.
void LevelLoop(sf::RenderWindow& window) {
    
    auto const levels = {1, 2, 3, 4, 5, 6};
    int sidelength;

    for (int i : levels) {
        if (i == 1) sidelength = 2;
        else if (1 < i < 6) sidelength = 3;
        else sidelength = 4;

		DungeonLevel level(sidelength);
		std::cout << "level " << i << std::endl;
		bool keeprunning = Level(window, level);
		if (!keeprunning) break;
	}
}





//#################################################################################################################
// This is a main function that creates the renderwindow and holds the application loop
int main() {
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Dungeon Crawler", sf::Style::Close);

	auto desktop = sf::VideoMode::getDesktopMode();
	sf::Vector2i posvec(desktop.width/2 - window.getSize().x/2, desktop.height/2 - window.getSize().y/2);
	window.setPosition(posvec);
    
    // Start menu items
    sf::Texture menu_texture;
    menu_texture.loadFromFile("../src/Graphics/GUI_Sprites/MainMenu.png");
    sf::Sprite main_menu(menu_texture);

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

	// Game view items
	sf::Texture game_texture;
    game_texture.loadFromFile("../src/Graphics/GUI_Sprites/UI_PIC.png");
    sf::Sprite game_view(game_texture);

	sf::RectangleShape end_game_button(sf::Vector2f(115, 115));
    end_game_button.setPosition(1415, 712);

    /*
    sf::Music start_music;
    start_music.openFromFile("../src/Sounds/Music/Placeholder.ogg");
	start_music.play();
    */

   	sf::Sprite test = SpriteContainer::ai_aggressive();
	//test.setPosition(sf::Vector2f(200, 200));

   	window.clear();
	window.draw(main_menu);
	window.draw(test);
	window.display();

	enum AppState {
		MainMenu,
		Game
	};

	AppState state = MainMenu;

	// The main application loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

			if (state == MainMenu) {
				if (event.type == event.MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
					sf::Vector2i mousePos = sf::Mouse::getPosition(window);
					if (quit_button.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
						window.close();
					}
					else if (start_button.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
						std::cout << "Start button pressed" << std::endl;
						state = Game;
						window.clear();
						window.draw(game_view);
						auto orig = game_view.getOrigin();
						std::cout << orig.x << " " << orig.y << std::endl;
						window.display();
						LevelLoop(window);
						//window.clear();
						//window.draw(main_menu);
						//state = MainMenu;
					}
					else if (instructions_button.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
						std::cout << "Instructions button pressed" << std::endl;
					}
				}
			}
			else if (state == Game) {
				if (event.type == event.MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
					sf::Vector2i mousePos = sf::Mouse::getPosition(window);
					if (end_game_button.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
						return false;
					}
        		}
    		}
		}
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

REMEMBER TO CHECK INVENTORY SLOT ITEM RETURN VALUE FOR RANGED & MELEE WEAPONS
IF THE ITEM IS A RANGED WEAPON, RETURN VALUE IS 10
*/





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
