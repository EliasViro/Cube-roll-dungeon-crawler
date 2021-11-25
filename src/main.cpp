
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


// This function draws a new room in its initial state.
void RenderScreen(sf::RenderWindow& window, std::vector<std::vector<DungeonTile*>> tile_matrix, bool islastroominlevel, std::vector<Character*> enemyvec, Character* player, int currentlevel, bool combatongoing) {

	//FIRST, CLEAR WINDOW, THEN DRAW UI SPRITE
	sf::Texture game_texture;
    game_texture.loadFromFile("../src/Graphics/GUI_Sprites/UI_PIC.png");
    sf::Sprite game_view(game_texture);
	
	window.clear();
	window.draw(game_view);

	// Create all sprites
	sf::Texture door_closed_t;
	door_closed_t.loadFromFile("../src/Graphics/TileSprites/DoorClosed.png"); //Closed door
	sf::Sprite sprite_door_closed(door_closed_t);

	sf::Texture floor_t;
	floor_t.loadFromFile("../src/Graphics/TileSprites/Floor.png"); //Floor
	sf::Sprite sprite_floor(floor_t);
	
	sf::Texture levelexitclosed_t;
	levelexitclosed_t.loadFromFile("../src/Graphics/TileSprites/LevelExitClosed.png"); //Closed level exit
	sf::Sprite sprite_levelexitclosed(levelexitclosed_t);

	sf::Texture levelexitopen_t;
	levelexitopen_t.loadFromFile("../src/Graphics/TileSprites/LevelExitOpen.png"); //Open level exit
	sf::Sprite sprite_levelexitopen(levelexitopen_t);

	sf::Texture pit_t;
	pit_t.loadFromFile("../src/Graphics/TileSprites/Pit.png"); //Pit
	sf::Sprite sprite_pit(pit_t);

	sf::Texture trap1_t;
	trap1_t.loadFromFile("../src/Graphics/TileSprites/Trap1.png"); //Trap in Dormant state
	sf::Sprite sprite_trap1(trap1_t);

	sf::Texture trap2_t;
	trap2_t.loadFromFile("../src/Graphics/TileSprites/Trap2.png"); //Trap in Emerging state
	sf::Sprite sprite_trap2(trap2_t);

	sf::Texture trap3_t;
	trap3_t.loadFromFile("../src/Graphics/TileSprites/Trap3.png"); //Trap in Spikes state
	sf::Sprite sprite_trap3(trap3_t);

	sf::Texture wall_t;
	wall_t.loadFromFile("../src/Graphics/TileSprites/Wall.png"); //Wall
	sf::Sprite sprite_wall(wall_t);

	sf::Texture healthpotion_t;
	healthpotion_t.loadFromFile("../src/Graphics/ItemSprites/HealthPotion.png"); //Potion of healing
	sf::Sprite sprite_healthpotion(healthpotion_t);

	sf::Texture staminapotion_t;
	staminapotion_t.loadFromFile("../src/Graphics/ItemSprites/StaminaPotion.png"); //Potion of stamina
	sf::Sprite sprite_staminapotion(staminapotion_t);

	sf::Texture shortsword_t;
	shortsword_t.loadFromFile("../src/Graphics/ItemSprites/ShortSword.png"); //Shortsword
	sf::Sprite sprite_shortsword(shortsword_t);

	sf::Texture armingsword_t;
	armingsword_t.loadFromFile("../src/Graphics/ItemSprites/ArmingSword.png"); //Arming sword
	sf::Sprite sprite_armingsword(armingsword_t);

	sf::Texture longsword_t;
	longsword_t.loadFromFile("../src/Graphics/ItemSprites/LongSword.png"); //Longsword
	sf::Sprite sprite_longsword(longsword_t);

	sf::Texture hatchet_t;
	hatchet_t.loadFromFile("../src/Graphics/ItemSprites/Hatchet.png"); //Hatchet
	sf::Sprite sprite_hatchet(hatchet_t);

	sf::Texture battleaxe_t;
	battleaxe_t.loadFromFile("../src/Graphics/ItemSprites/BattleAxe.png"); //Battleaxe
	sf::Sprite sprite_battleaxe(battleaxe_t);

	sf::Texture mace_t;
	mace_t.loadFromFile("../src/Graphics/ItemSprites/Mace.png"); //Mace
	sf::Sprite sprite_mace(mace_t);

	sf::Texture warhammer_t;
	warhammer_t.loadFromFile("../src/Graphics/ItemSprites/WarHammer.png"); //Warhammer
	sf::Sprite sprite_warhammer(warhammer_t);

	sf::Texture roundshield_t;
	roundshield_t.loadFromFile("../src/Graphics/ItemSprites/RoundShield.png"); //Round shield
	sf::Sprite sprite_roundshield(roundshield_t);

	sf::Texture heatershield_t;
	heatershield_t.loadFromFile("../src/Graphics/ItemSprites/HeaterShield.png"); //Heater shield
	sf::Sprite sprite_heatershield(heatershield_t);

	sf::Texture kiteshield_t;
	kiteshield_t.loadFromFile("../src/Graphics/ItemSprites/KiteShield.png"); //Kite shield
	sf::Sprite sprite_kiteshield(kiteshield_t);

	sf::Texture towershield_t;
	towershield_t.loadFromFile("../src/Graphics/ItemSprites/TowerShield.png"); //Tower shield
	sf::Sprite sprite_towershield(towershield_t);

	sf::Texture sling_t;
	sling_t.loadFromFile("../src/Graphics/ItemSprites/Sling.png"); //Sling
	sf::Sprite sprite_sling(sling_t);

	sf::Texture bolas_t;
	bolas_t.loadFromFile("../src/Graphics/ItemSprites/Bolas.png"); //Bolas
	sf::Sprite sprite_bolas(bolas_t);

	sf::Texture javelin_t;
	javelin_t.loadFromFile("../src/Graphics/ItemSprites/Javelin.png"); //Javelin
	sf::Sprite sprite_javelin(javelin_t);

	sf::Texture aiaggressive_t;
	aiaggressive_t.loadFromFile("../src/Graphics/CharacterSprites/AI_Aggressive.png"); //Aggressive AI
	sf::Sprite sprite_aiaggressive(aiaggressive_t);

	sf::Texture aicareful_t;
	aicareful_t.loadFromFile("../src/Graphics/CharacterSprites/AI_Careful.png"); //Careful AI
	sf::Sprite sprite_aicareful(aicareful_t);

	sf::Texture aiboss_t;
	aiboss_t.loadFromFile("../src/Graphics/CharacterSprites/AI_Boss.png"); //Boss AI
	sf::Sprite sprite_aiboss(aiboss_t);

	sf::Texture airandom_t;
	airandom_t.loadFromFile("../src/Graphics/CharacterSprites/AI_Random.png"); //Random AI
	sf::Sprite sprite_airandom(airandom_t);

	sf::Texture aistunned_t;
	aistunned_t.loadFromFile("../src/Graphics/CharacterSprites/AI_Stunned.png"); //Stunned character
	sf::Sprite sprite_aistunned(aistunned_t);

	sf::Texture defense1_t;
	defense1_t.loadFromFile("../src/Graphics/CharacterSprites/Defense1.png"); //Defense 1
	sf::Sprite sprite_defense1(defense1_t);

	sf::Texture defense2_t;
	defense2_t.loadFromFile("../src/Graphics/CharacterSprites/Defense2.png"); //Defense 2
	sf::Sprite sprite_defense2(defense2_t);

	sf::Texture defense3_t;
	defense3_t.loadFromFile("../src/Graphics/CharacterSprites/Defense3.png"); //Defense 3
	sf::Sprite sprite_defense3(defense3_t);

	sf::Texture melee1_t;
	melee1_t.loadFromFile("../src/Graphics/CharacterSprites/Melee1.png"); //Melee 1
	sf::Sprite sprite_melee1(melee1_t);

	sf::Texture melee2_t;
	melee2_t.loadFromFile("../src/Graphics/CharacterSprites/Melee2.png"); //Melee 2
	sf::Sprite sprite_melee2(melee2_t);

	sf::Texture melee3_t;
	melee3_t.loadFromFile("../src/Graphics/CharacterSprites/Melee3.png"); //Melee 3
	sf::Sprite sprite_melee3(melee3_t);

	sf::Texture ranged1_t;
	ranged1_t.loadFromFile("../src/Graphics/CharacterSprites/Ranged1.png"); //Ranged 1
	sf::Sprite sprite_ranged1(ranged1_t);

	sf::Texture ranged2_t;
	ranged2_t.loadFromFile("../src/Graphics/CharacterSprites/Ranged2.png"); //Ranged 2
	sf::Sprite sprite_ranged2(ranged2_t);

	sf::Texture ranged3_t;
	ranged3_t.loadFromFile("../src/Graphics/CharacterSprites/Ranged3.png"); //Ranged 3
	sf::Sprite sprite_ranged3(ranged3_t);

	sf::Texture emptyaction_t;
	emptyaction_t.loadFromFile("../src/Graphics/CharacterSprites/Empty.png"); //Empty action
	sf::Sprite sprite_emptyaction(emptyaction_t);

	sf::Texture enemybase_t;
	enemybase_t.loadFromFile("../src/Graphics/CharacterSprites/Enemy.png"); //Enemy base tile
	sf::Sprite sprite_enemybase(enemybase_t);

	sf::Texture playerbase_t;
	playerbase_t.loadFromFile("../src/Graphics/CharacterSprites/Player.png"); //Player base tile
	sf::Sprite sprite_playerbase(playerbase_t);

	sf::Texture depth1_t;
	depth1_t.loadFromFile("../src/Graphics/GUI_Sprites/Depth1.png"); //Depth 1 indicator
	sf::Sprite sprite_depth1(depth1_t);

	sf::Texture depth2_t;
	depth2_t.loadFromFile("../src/Graphics/GUI_Sprites/Depth2.png"); //Depth 2 indicator
	sf::Sprite sprite_depth2(depth2_t);

	sf::Texture depth3_t;
	depth3_t.loadFromFile("../src/Graphics/GUI_Sprites/Depth3.png"); //Depth 3 indicator
	sf::Sprite sprite_depth3(depth3_t);

	sf::Texture depth4_t;
	depth4_t.loadFromFile("../src/Graphics/GUI_Sprites/Depth4.png"); //Depth 4 indicator
	sf::Sprite sprite_depth4(depth4_t);

	sf::Texture depth5_t;
	depth5_t.loadFromFile("../src/Graphics/GUI_Sprites/Depth5.png"); //Depth 5 indicator
	sf::Sprite sprite_depth5(depth5_t);

	sf::Texture depth6_t;
	depth6_t.loadFromFile("../src/Graphics/GUI_Sprites/Depth6.png"); //Depth 6 indicator
	sf::Sprite sprite_depth6(depth6_t);

	sf::Texture health0_t;
	health0_t.loadFromFile("../src/Graphics/GUI_Sprites/Health0.png"); //Health 0 indicator
	sf::Sprite sprite_health0(health0_t);

	sf::Texture health1_t;
	health1_t.loadFromFile("../src/Graphics/GUI_Sprites/Health1.png"); //Health 1 indicator
	sf::Sprite sprite_health1(health1_t);

	sf::Texture health2_t;
	health2_t.loadFromFile("../src/Graphics/GUI_Sprites/Health2.png"); //Health 2 indicator
	sf::Sprite sprite_health2(health2_t);

	sf::Texture health3_t;
	health3_t.loadFromFile("../src/Graphics/GUI_Sprites/Health3.png"); //Health 3 indicator
	sf::Sprite sprite_health3(health3_t);

	sf::Texture health4_t;
	health4_t.loadFromFile("../src/Graphics/GUI_Sprites/Health4.png"); //Health 4 indicator
	sf::Sprite sprite_health4(health4_t);

	sf::Texture nrzero_t;
	nrzero_t.loadFromFile("../src/Graphics/GUI_Sprites/0.png"); //0
	sf::Sprite sprite_nrzero(nrzero_t);

	sf::Texture nrone_t;
	nrone_t.loadFromFile("../src/Graphics/GUI_Sprites/1.png"); //1
	sf::Sprite sprite_nrone(nrone_t);

	sf::Texture nrtwo_t;
	nrtwo_t.loadFromFile("../src/Graphics/GUI_Sprites/2.png"); //2
	sf::Sprite sprite_nrtwo(nrtwo_t);

	sf::Texture nrthree_t;
	nrthree_t.loadFromFile("../src/Graphics/GUI_Sprites/3.png"); //3
	sf::Sprite sprite_nrthree(nrthree_t);

	sf::Texture nrfour_t;
	nrfour_t.loadFromFile("../src/Graphics/GUI_Sprites/4.png"); //4
	sf::Sprite sprite_nrfour(nrfour_t);

	sf::Texture nrfive_t;
	nrfive_t.loadFromFile("../src/Graphics/GUI_Sprites/5.png"); //5
	sf::Sprite sprite_nrfive(nrfive_t);

	sf::Texture nrsix_t;
	nrsix_t.loadFromFile("../src/Graphics/GUI_Sprites/6.png"); //6
	sf::Sprite sprite_nrsix(nrsix_t);

	sf::Texture nrseven_t;
	nrseven_t.loadFromFile("../src/Graphics/GUI_Sprites/7.png"); //7
	sf::Sprite sprite_nrseven(nrseven_t);

	sf::Texture nreight_t;
	nreight_t.loadFromFile("../src/Graphics/GUI_Sprites/8.png"); //8
	sf::Sprite sprite_nreight(nreight_t);

	sf::Texture nrinf_t;
	nrinf_t.loadFromFile("../src/Graphics/GUI_Sprites/Inf.png"); //Inf
	sf::Sprite sprite_nrinf(nrinf_t);

	sf::Texture att_t;
	att_t.loadFromFile("../src/Graphics/GUI_Sprites/Att.png"); //Att
	sf::Sprite sprite_att(att_t);

	sf::Texture defse_t;
	defse_t.loadFromFile("../src/Graphics/GUI_Sprites/Def.png"); //Def
	sf::Sprite sprite_defse(defse_t);

	sf::Texture coold_t;
	coold_t.loadFromFile("../src/Graphics/GUI_Sprites/CD.png"); //CD
	sf::Sprite sprite_coold(coold_t);

	sf::Texture maxcoold_t;
	maxcoold_t.loadFromFile("../src/Graphics/GUI_Sprites/TCD.png"); //TCD
	sf::Sprite sprite_maxcoold(maxcoold_t);

	sf::Texture dur_t;
	dur_t.loadFromFile("../src/Graphics/GUI_Sprites/Dur.png"); //Dur
	sf::Sprite sprite_dur(dur_t);

	sf::Texture nonum_t;
	nonum_t.loadFromFile("../src/Graphics/GUI_Sprites/NoNum.png"); //NoNum
	sf::Sprite sprite_nonum(nonum_t);

	int x_orig = 65;
	int y_orig = 67;
	
	for (std::vector<DungeonTile*> i : tile_matrix) {
		for (DungeonTile* tile : i) {
			sf::Sprite sprite;
			sf::Sprite itemsprite;
			int x = x_orig + (tile->GetXCoord())*64;
			int y = y_orig + (tile->GetYCoord())*64;

			TileType tiletype = tile->GetTileType();
			if (tiletype == Floor || tiletype == Spawner || tiletype == Entrance || tiletype == Loot) {
				sprite = sprite_floor;
			}
			else if (tiletype == Wall) {
				sprite = sprite_wall;				
			}
			else if (tiletype == Pit) {
				sprite = sprite_pit;
			}
			else if (tiletype == Door) {
				if (!tile->IsOpen()) {
					sprite = sprite_door_closed;
				}
				else {
					sprite = sprite_floor;
				}
			}
			else if (tiletype == Trap) {
				if (tile->GetTrapState() == Dormant) {
					sprite = sprite_trap1;
				}
				else if (tile->GetTrapState() == Emerging) {
					sprite = sprite_trap2;
				}
				else {
					sprite = sprite_trap3;
				}
			}
			else if (tiletype == Exit) {
				if (islastroominlevel) {
					if (!tile->IsOpen()) {
						sprite = sprite_levelexitclosed;
					}
					else {
						sprite = sprite_levelexitopen;
					}
				}
				else {
					sprite = sprite_floor;
				}
			}
			sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
			window.draw(sprite);

			if (tile->GetItem() != nullptr) {
				auto item = tile->GetItem();
				if (item->GetName() == "Potion of healing") {
					itemsprite = sprite_healthpotion;
				}
				else if (item->GetName() == "Potion of stamina") {
					itemsprite = sprite_staminapotion;
				}
				else if (item->GetName() == "Javelin") {
					itemsprite = sprite_javelin;
				}
				else if (item->GetName() == "Bolas") {
					itemsprite = sprite_bolas;
				}
				else if (item->GetName() == "Sling") {
					itemsprite = sprite_sling;
				}
				else if (item->GetName() == "Round shield") {
					itemsprite = sprite_roundshield;
				}
				else if (item->GetName() == "Heater shield") {
					itemsprite = sprite_heatershield;
				}
				else if (item->GetName() == "Kite shield") {
					itemsprite = sprite_kiteshield;
				}
				else if (item->GetName() == "Tower shield") {
					itemsprite = sprite_towershield;
				}
				else if (item->GetName() == "Shortsword") {
					itemsprite = sprite_shortsword;
				}
				else if (item->GetName() == "Arming sword") {
					itemsprite = sprite_armingsword;
				}
				else if (item->GetName() == "Longsword") {
					itemsprite = sprite_longsword;
				}
				else if (item->GetName() == "Hatchet") {
					itemsprite = sprite_hatchet;
				}
				else if (item->GetName() == "Battleaxe") {
					itemsprite = sprite_battleaxe;
				}
				else if (item->GetName() == "Mace") {
					itemsprite = sprite_mace;
				}
				else if (item->GetName() == "Warhammer") {
					itemsprite = sprite_warhammer;	
				}
				itemsprite.setPosition(static_cast<float>(x), static_cast<float>(y));
				window.draw(itemsprite);
			}
		}
	}
    for (auto enemy : enemyvec) {
		sf::Sprite enemysprite = sprite_enemybase;
		sf::Sprite weaponsprite;
		sf::Sprite statussprite;
		if (enemy != nullptr) {
			int xcoord = enemy->GetXCoordinate();
			int ycoord = enemy->GetYCoordinate();
			int x = x_orig + (xcoord) * 64;
			int y = y_orig + (ycoord) * 64;
			ActionType currentaction = enemy->GetCurrentAction();
			EnemyAI currentAI = enemy->GetEnemyAI();
			//Draw the basic black enemy sprite here, the rest is drawn on top of it.
			if (currentaction == Melee_1) {
				//Draw the sword
				weaponsprite = sprite_melee1;
			}
			else if (currentaction == Melee_2) {
				//Draw the warhammer
				weaponsprite = sprite_melee2;
			}
			else if (currentaction == Melee_3) {
				//Draw the axe
				weaponsprite = sprite_melee3;
			}
			else if (currentaction == Ranged_1) {
				//Draw the smallest bow
				weaponsprite = sprite_ranged1;
			}
			else if (currentaction == Ranged_2) {
				//Draw the medium sized bow
				weaponsprite = sprite_ranged2;
			}
			else if (currentaction == Ranged_3) {
				//Draw the largest bow
				weaponsprite = sprite_ranged3;
			}
			else if (currentaction == Defend_1) {
				//Draw the shield with number 1
				weaponsprite = sprite_defense1;
			}
			else if (currentaction == Defend_2) {
				//Draw the shield with number 2
				weaponsprite = sprite_defense2;
			}
			else if (currentaction == Defend_3) {
				//Draw the shield with number 3
				weaponsprite = sprite_defense3;
			}
			else {
				//Draw the empty enemy sprite (has zero at top right corner)
				weaponsprite = sprite_emptyaction;
			}

			if (enemy->IsStunned()) {
				//Draw the Stunned AI symbol
				statussprite = sprite_aistunned;
			}
			else if (currentAI == Aggressive) {
				//Draw the Aggressive AI symbol
				statussprite = sprite_aiaggressive;
			}
			else if (currentAI == Careful) {
				//Draw the Careful AI symbol
				statussprite = sprite_aicareful;
			}
			else if (currentAI == Random) {
				//Draw the Random AI symbol
				statussprite = sprite_airandom;
			}
			else {
				//Draw the Boss AI symbol
				statussprite = sprite_aiboss;
			}

			for (auto sprite : {enemysprite, weaponsprite, statussprite}) {
				sprite.setPosition(static_cast<float>(x), static_cast<float>(y));
				window.draw(sprite);
			}
		}
	}
	if (player != nullptr) {
		sf::Sprite healthsprite;
		sf::Sprite lvlsprite;
		int playerxcoord = player->GetXCoordinate();
		int playerycoord = player->GetYCoordinate();
		int x = x_orig + (playerxcoord) * 64;
		int y = y_orig + (playerycoord) * 64;
		auto inventory = player->GetInventory();
		int playerhp = player->GetHealthPoints();
		if (playerhp == 0) {
			healthsprite = sprite_health0;
		}
		else if (playerhp == 1) {
			healthsprite = sprite_health1;
		}
		else if (playerhp == 2) {
			healthsprite = sprite_health2;
		}
		else if (playerhp == 3) {
			healthsprite = sprite_health3;
		}
		else {
			healthsprite = sprite_health4;
		}
		healthsprite.setPosition(972, 78);
		window.draw(healthsprite);

		if (currentlevel == 1) {
			lvlsprite = sprite_depth1;
		}
		else if (currentlevel == 2) {
			lvlsprite = sprite_depth2;
		}
		else if (currentlevel == 3) {
			lvlsprite = sprite_depth3;
		}
		else if (currentlevel == 4) {
			lvlsprite = sprite_depth4;
		}
		else if (currentlevel == 5) {
			lvlsprite = sprite_depth5;
		}
		else {
			lvlsprite = sprite_depth6;
		}
		lvlsprite.setPosition(1421, 78);
		window.draw(lvlsprite);

		sprite_playerbase.setPosition(x, y);
		window.draw(sprite_playerbase);
		
		for (int inventoryindex = 0; inventoryindex < 6; inventoryindex++) {
			sf::Sprite item;
			sf::Sprite attackdefense;
			sf::Sprite durability;
			sf::Sprite cooldown;
			sf::Sprite topcooldown;
			sf::Sprite durnumber;
			sf::Sprite attdefnumber;
			sf::Sprite cdnumber;
			sf::Sprite topcdnumber;
			if (!inventory[inventoryindex]->IsEmpty()) {
				auto invitem = inventory[inventoryindex]->GetItem();
				topcooldown = sprite_maxcoold;
				cooldown = sprite_coold;
				attackdefense = sprite_nonum;
				durnumber = sprite_nrinf;
				durability = sprite_dur;
				if (invitem->GetItemType() == ShieldItem) {
					attackdefense = sprite_defse;
					if (invitem->GetDefense() == 0) {
						attdefnumber = sprite_nrzero;
					}
					if (invitem->GetDefense() == 1) {
						attdefnumber = sprite_nrone;
					}
					if (invitem->GetDefense() == 2) {
						attdefnumber = sprite_nrtwo;
					}
					if (invitem->GetDefense() == 3) {
						attdefnumber = sprite_nrthree;
					}
				}
				if (invitem->GetItemType() == MeleeWeaponItem || invitem->GetItemType() == RangedWeaponItem) {
					attackdefense = sprite_att;
					if (invitem->GetDamage() == 0) {
						attdefnumber = sprite_nrzero;
					}
					if (invitem->GetDamage() == 1) {
						attdefnumber = sprite_nrone;
					}
					if (invitem->GetDamage() == 2) {
						attdefnumber = sprite_nrtwo;
					}
					if (invitem->GetDamage() == 3) {
						attdefnumber = sprite_nrthree;
					}
				}
				if (invitem->GetMaxCoolDown() == 1) {
					topcdnumber = sprite_nrone;
				}
				if (invitem->GetMaxCoolDown() == 2) {
					topcdnumber = sprite_nrtwo;
				}
				if (invitem->GetMaxCoolDown() == 3) {
					topcdnumber = sprite_nrthree;
				}
				if (invitem->GetMaxCoolDown() == 4) {
					topcdnumber = sprite_nrfour;
				}
				if (invitem->GetMaxCoolDown() == 5) {
					topcdnumber = sprite_nrfive;
				}
				if (invitem->GetMaxCoolDown() == 6) {
					topcdnumber = sprite_nrsix;
				}
				if (invitem->GetMaxCoolDown() == 7) {
					topcdnumber = sprite_nrseven;
				}
				if (invitem->GetMaxCoolDown() == 8) {
					topcdnumber = sprite_nreight;
				}
				if (invitem->GetCoolDown() == 0) {
					cdnumber = sprite_nrzero;
				}
				if (invitem->GetCoolDown() == 1) {
					cdnumber = sprite_nrone;
				}
				if (invitem->GetCoolDown() == 2) {
					cdnumber = sprite_nrtwo;
				}
				if (invitem->GetCoolDown() == 3) {
					cdnumber = sprite_nrthree;
				}
				if (invitem->GetCoolDown() == 4) {
					cdnumber = sprite_nrfour;
				}
				if (invitem->GetCoolDown() == 5) {
					cdnumber = sprite_nrfive;
				}
				if (invitem->GetCoolDown() == 6) {
					cdnumber = sprite_nrsix;
				}
				if (invitem->GetCoolDown() == 7) {
					cdnumber = sprite_nrseven;
				}
				if (invitem->GetCoolDown() == 8) {
					cdnumber = sprite_nreight;
				}

				if (invitem->GetName() == "Potion of healing") {
					item = sprite_healthpotion;
					topcooldown = sprite_nonum;
					cooldown = sprite_nonum;
					durnumber = sprite_nrone;
					attdefnumber = sprite_nonum;
					cdnumber = sprite_nonum;
					topcdnumber = sprite_nonum;

				}
				else if (invitem->GetName() == "Potion of stamina") {
					item = sprite_staminapotion;
					topcooldown = sprite_nonum;
					cooldown = sprite_nonum;
					durnumber = sprite_nrone;
					attdefnumber = sprite_nonum;
					cdnumber = sprite_nonum;
					topcdnumber = sprite_nonum;
				}
				else if (invitem->GetName() == "Javelin") {
					item = sprite_javelin;
				}
				else if (invitem->GetName() == "Bolas") {
					item = sprite_bolas;
				}
				else if (invitem->GetName() == "Sling") {
					item = sprite_sling;
				}
				else if (invitem->GetName() == "Round shield") {
					item = sprite_roundshield;
				}
				else if (invitem->GetName() == "Heater shield") {
					item = sprite_heatershield;
					durability = sprite_nrinf;
				}
				else if (invitem->GetName() == "Kite shield") {
					item = sprite_kiteshield;
				}
				else if (invitem->GetName() == "Tower shield") {
					item = sprite_towershield;
				}
				else if (invitem->GetName() == "Shortsword") {
					item = sprite_shortsword;
				}
				else if (invitem->GetName() == "Arming sword") {
					item = sprite_armingsword;
				}
				else if (invitem->GetName() == "Longsword") {
					item = sprite_longsword;
				}
				else if (invitem->GetName() == "Hatchet") {
					item = sprite_hatchet;
				}
				else if (invitem->GetName() == "Battleaxe") {
					item = sprite_battleaxe;
				}
				else if (invitem->GetName() == "Mace") {
					item = sprite_mace;
				}
				else {
					item = sprite_warhammer;
				}
				
				if (inventoryindex == 0) {
					// Top & player tile
					item.setPosition(1216, 322);
					sf::Sprite item2 = item;
					int x = x_orig + (player->GetXCoordinate())*64;
					int y = y_orig + (player->GetYCoordinate())*64;
					item2.setPosition(x, y);
					attdefnumber.setPosition(1157, 263);
					attackdefense.setPosition(1157,263);
					topcooldown.setPosition(1285, 391);
					topcdnumber.setPosition(1285, 391);
					cooldown.setPosition(1157, 391);
					cdnumber.setPosition(1157, 391);
					durability.setPosition(1285, 263);
					durnumber.setPosition(1285, 263);
				}
				else if (inventoryindex == 1) {
					// N
					item.setPosition(1216, 131);
					attdefnumber.setPosition(1157, 71);
					attackdefense.setPosition(1157, 71);
					topcooldown.setPosition(1285, 199);
					topcdnumber.setPosition(1285, 199);
					cooldown.setPosition(1157, 199);
					cdnumber.setPosition(1157, 199);
					durability.setPosition(1285, 71);
					durnumber.setPosition(1285, 71);
				}
				else if (inventoryindex == 2) {
					// E
					item.setPosition(1408, 322);
					attdefnumber.setPosition(1349, 263);
					attackdefense.setPosition(1349,263);
					topcooldown.setPosition(1477, 391);
					topcdnumber.setPosition(1477, 391);
					cooldown.setPosition(1349, 391);
					cdnumber.setPosition(1349, 391);
					durability.setPosition(1477, 263);
					durnumber.setPosition(1477, 263);
				}
				else if (inventoryindex == 3) {
					// W
					item.setPosition(1024, 322);
					attdefnumber.setPosition(965, 263);
					attackdefense.setPosition(965,263);
					topcooldown.setPosition(1093, 391);
					topcdnumber.setPosition(1093, 391);
					cooldown.setPosition(965, 391);
					cdnumber.setPosition(965, 391);
					durability.setPosition(1093, 263);
					durnumber.setPosition(1093, 263);
				}
				else if (inventoryindex == 4) {
					// S
					item.setPosition(1216, 515);
					item.setPosition(1216, 131);
					attdefnumber.setPosition(1157, 455);
					attackdefense.setPosition(1157, 455);
					topcooldown.setPosition(1285, 583);
					topcdnumber.setPosition(1285, 583);
					cooldown.setPosition(1157, 583);
					cdnumber.setPosition(1157, 583);
					durability.setPosition(1285, 455);
					durnumber.setPosition(1285, 455);
				}
				else {
					// Bottom
					item.setPosition(1216, 706);
					attdefnumber.setPosition(1157, 647);
					attackdefense.setPosition(1157, 647);
					topcooldown.setPosition(1285, 775);
					topcdnumber.setPosition(1285, 775);
					cooldown.setPosition(1157, 775);
					cdnumber.setPosition(1157, 775);
					durability.setPosition(1285, 647);
					durnumber.setPosition(1285, 647);
				}
				// which index --> position --> sprite
			}
			window.draw(item);
		}
	}
	
	window.display();
}




//#####################################################################################################
//
void CharacterInfo() {
	
}





//#####################################################################################################
//This function holds a game loop for one room in a dungeon.
bool Level(sf::RenderWindow& window, DungeonLevel level, int depth, Character* player, std::vector<std::vector<Item*>> lootvector) {
	std::vector<std::vector<DungeonRoom*>> rooms = level.GetRooms();
	DungeonRoom* currentroom = rooms[level.GetStartPos().first][level.GetStartPos().second];
    bool lootgiven = false;
	bool lastroominlevelset = false;
    int randomnumberx = rand() % (level.GetSideLength()); //Random number for loot placement
    int randomnumbery = rand() % (level.GetSideLength()); //Random number for loot placement
    for (auto loot : lootvector[depth]) { //Give random rooms loot.
        while (!lootgiven) {
            randomnumberx = rand() % (level.GetSideLength());
            randomnumbery = rand() % (level.GetSideLength());
            if (rooms[randomnumberx][randomnumbery]->GetIndexInLevel() != currentroom->GetIndexInLevel() && rooms[randomnumberx][randomnumbery]->GetLootItem() == nullptr) {
                rooms[randomnumberx][randomnumbery]->GiveLoot(loot);
                lootgiven = true;
            }
        }
        lootgiven = false;
    }
    int exploredroomscounter = 1;
    int levelroomcount = level.GetSideLength() * level.GetSideLength();
    int levelycoord = level.GetStartPos().first;
    int levelxcoord = level.GetStartPos().second;
    bool loopbreaker = false;
    bool combat = false;
    int enemiesalive = 0;
    std::vector<Character*> enemyvector = {nullptr};
    for (auto tilevec : currentroom->GetAllTiles()) {
        for (auto tile : tilevec) {
            if (tile->GetTileType() == Entrance) {
                player->MoveToTile(tile);
                loopbreaker = true;
                break;
            }
        }
        if (loopbreaker) {
            break;
        }
    }
    
	// Define all game view buttons
	sf::RectangleShape end_game_button(sf::Vector2f(115, 115));
    end_game_button.setPosition(1415, 712);

	sf::RectangleShape button1(sf::Vector2f(115, 115));
    button1.setPosition(966, 72);

	sf::RectangleShape button2(sf::Vector2f(115, 115));
    button2.setPosition(1414, 72);

	sf::RectangleShape button3(sf::Vector2f(115, 115));
    button3.setPosition(966, 519);

	sf::RectangleShape button4(sf::Vector2f(115, 115));
    button4.setPosition(1414, 519);

	sf::RectangleShape button5(sf::Vector2f(115, 115));
    button5.setPosition(966, 712);

	sf::ConvexShape north;
    north.setPointCount(3);
    north.setPoint(0, sf::Vector2f(448, 13));
    north.setPoint(1, sf::Vector2f(482, 50));
	north.setPoint(2, sf::Vector2f(414, 50));

	sf::ConvexShape west;
    west.setPointCount(3);
    west.setPoint(0, sf::Vector2f(12, 448));
    west.setPoint(1, sf::Vector2f(48, 414));
	west.setPoint(2, sf::Vector2f(48, 482));

	sf::ConvexShape south;
    south.setPointCount(3);
    south.setPoint(0, sf::Vector2f(448, 886));
    south.setPoint(1, sf::Vector2f(412, 847));
	south.setPoint(2, sf::Vector2f(482, 849));

	sf::ConvexShape east;
    east.setPointCount(3);
	east.setPoint(0, sf::Vector2f(884, 448));
    east.setPoint(1, sf::Vector2f(848, 484));
	east.setPoint(2, sf::Vector2f(846, 414));

	// Game loop
	bool run = true;
	while (run) {
		RenderScreen(window, currentroom->GetAllTiles(), currentroom->IsLastRoomInLevel(), enemyvector, player, depth, combat);
		// Player input loop
		int validmove = -1;
		while (validmove < 0) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) continue;

				sf::Vector2i mousePos = sf::Mouse::getPosition(window);
				if (end_game_button.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
					std::cout << "game exit button pressed" << std::endl;
					return false;
				}
				else if (button1.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
					std::cout << "button1 pressed" << std::endl;
				}
				else if (button2.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
					std::cout << "button2 pressed" << std::endl;
				}
				else if (button3.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
					std::cout << "button3 pressed" << std::endl;
				}
				else if (button4.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
					std::cout << "button4 pressed" << std::endl;
				}
				else if (button5.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
					std::cout << "button5 pressed" << std::endl;
				}
				else if (north.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
					std::cout << "north pressed" << std::endl;
					validmove = player->MoveToDirection("N");
				}
				else if (east.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
					std::cout << "east pressed" << std::endl;
					validmove = player->MoveToDirection("E");
				}
				else if (south.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
					std::cout << "south pressed" << std::endl;
					validmove = player->MoveToDirection("S");
				}
				else if (west.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
					std::cout << "west pressed" << std::endl;
					validmove = player->MoveToDirection("W");				
				}
			}
		}

		//After moving, check if the player is on a door tile. This will move the player to the next room in that direction.
		if (player->GetCurrentTile() == currentroom->GetAllTiles()[0][5] || player->GetCurrentTile() == currentroom->GetAllTiles()[0][6] ||
		player->GetCurrentTile() == currentroom->GetAllTiles()[11][5] || player->GetCurrentTile() == currentroom->GetAllTiles()[11][6] ||
		player->GetCurrentTile() == currentroom->GetAllTiles()[5][11] || player->GetCurrentTile() == currentroom->GetAllTiles()[6][11] ||
		player->GetCurrentTile() == currentroom->GetAllTiles()[5][0] || player->GetCurrentTile() == currentroom->GetAllTiles()[6][0]) {
			if (player->GetCurrentTile() == currentroom->GetAllTiles()[0][5]) {
				player->MoveToTile(currentroom->GetNeighbors()[2]->GetAllTiles()[10][5]);
				currentroom = currentroom->GetNeighbors()[2];
			}
			if (player->GetCurrentTile() == currentroom->GetAllTiles()[0][6]) {
				player->MoveToTile(currentroom->GetNeighbors()[2]->GetAllTiles()[10][6]);
				currentroom = currentroom->GetNeighbors()[2];
			}
			if (player->GetCurrentTile() == currentroom->GetAllTiles()[11][5]) {
				player->MoveToTile(currentroom->GetNeighbors()[1]->GetAllTiles()[1][5]);
				currentroom = currentroom->GetNeighbors()[1];
			}
			if (player->GetCurrentTile() == currentroom->GetAllTiles()[11][6]) {
				player->MoveToTile(currentroom->GetNeighbors()[1]->GetAllTiles()[1][6]);
				currentroom = currentroom->GetNeighbors()[1];
			}
			if (player->GetCurrentTile() == currentroom->GetAllTiles()[5][11]) {
				player->MoveToTile(currentroom->GetNeighbors()[3]->GetAllTiles()[5][1]);
				currentroom = currentroom->GetNeighbors()[3];
			}
			if (player->GetCurrentTile() == currentroom->GetAllTiles()[6][11]) {
				player->MoveToTile(currentroom->GetNeighbors()[3]->GetAllTiles()[6][1]);
				currentroom = currentroom->GetNeighbors()[3];
			}
			if (player->GetCurrentTile() == currentroom->GetAllTiles()[5][0]) {
				player->MoveToTile(currentroom->GetNeighbors()[0]->GetAllTiles()[5][10]);
				currentroom = currentroom->GetNeighbors()[0];
			}
			if (player->GetCurrentTile() == currentroom->GetAllTiles()[6][0]) {
				player->MoveToTile(currentroom->GetNeighbors()[0]->GetAllTiles()[6][10]);
				currentroom = currentroom->GetNeighbors()[0];
			}
		
			if (!currentroom->IsExplored()) {
				exploredroomscounter++;
				enemyvector.clear();
				enemyvector = GenerateRoomEnemies(depth);
				currentroom->SpawnEnemies(enemyvector); //Enemies may be spawned and doors close if there are enemies present.
				for (auto enemyinvec : enemyvector) {
					if (enemyinvec != nullptr) {
						combat = true; //Combat value is set to true.
						enemiesalive++;
					}
				}
			}
			if (exploredroomscounter == levelroomcount && !lastroominlevelset) {
				currentroom->SetLastRoomInLevel();
				lastroominlevelset = true;
			}
			continue;
		}

		RenderScreen(window, currentroom->GetAllTiles(), currentroom->IsLastRoomInLevel(), enemyvector, player, depth, combat);

		if (player->GetCurrentTile()->GetTileType() == Exit && player->GetCurrentTile()->IsOpen()) {
			return true;
		}

		if (enemiesalive == 0) {
			currentroom->OpenDoors();
			combat = false;
		}

		if (exploredroomscounter == levelroomcount && enemiesalive == 0 && player->GetCurrentTile()->GetTileType() != Exit) {
			for (auto dungeontilevec : currentroom->GetAllTiles()) {
				for (auto exittile : dungeontilevec) {
					if (exittile->GetTileType() == Exit) {
						exittile->Open();
					}
				}
			}
		} //Open level exit

		for (auto traptilevec : currentroom->GetAllTiles()) {
			for (auto trap : traptilevec) {
				trap->ProceedTrapState();
			}
		}

		RenderScreen(window, currentroom->GetAllTiles(), currentroom->IsLastRoomInLevel(), enemyvector, player, depth, combat);

		for (auto enemy : enemyvector) {
			if (enemy != nullptr) {
				if (enemy->GetHealthPoints() > 0) {
					enemy->TakeAction(player, 1);
				}
			}
		}
		
		RenderScreen(window, currentroom->GetAllTiles(), currentroom->IsLastRoomInLevel(), enemyvector, player, depth, combat);

		for (int enemyindex = 0; enemyindex < enemyvector.size(); enemyindex++) {
			if (enemyvector[enemyindex] != nullptr) {
				if (enemyvector[enemyindex]->GetHealthPoints() <= 0) {
					enemyvector[enemyindex] = nullptr;
					enemiesalive--;
				}
			}
		}

		/*
		if (player->GetHealthPoints() <= 0) {
			//GAME OVER
			return false;
		}
		*/

		RenderScreen(window, currentroom->GetAllTiles(), currentroom->IsLastRoomInLevel(), enemyvector, player, depth, combat);
	}
	return false;
}





//#############################################################################################################
// This function loops through the six levels of one game instance.
void LevelLoop(sf::RenderWindow& window) {
    
    auto const levels = {1, 2, 3, 4, 5, 6};
    int sidelength;
    std::vector<std::vector<Item*>> lootvector = CreateLoot();
    Character* player = new Player(nullptr);
    
    for (int i : levels) {
        if (i == 1) sidelength = 2;
        else if (1 < i < 6) sidelength = 3;
        else sidelength = 4;

		DungeonLevel level(sidelength);
		bool keeprunning = Level(window, level, i, player, lootvector);
		if (!keeprunning) break;
	}
}


void testsignal(sf::RenderWindow& window) {
	sf::RectangleShape test_button(sf::Vector2f(115, 115));
    test_button.setPosition(1,1);

	sf::ConvexShape quit_button;
    quit_button.setPointCount(4);
    quit_button.setPoint(0, sf::Vector2f(500, 261));
    quit_button.setPoint(1, sf::Vector2f(782, 399));
    quit_button.setPoint(2, sf::Vector2f(782, 743));
    quit_button.setPoint(3, sf::Vector2f(500, 597));
	
	bool run = true;
	while (run) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) continue;

			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			if (test_button.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
				std::cout << "test button pressed" << std::endl;
			}
			else if (quit_button.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
				std::cout << "quit button pressed" << std::endl;
				break;
		}
	}

}
return;
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
	/*sf::Texture game_texture;
    game_texture.loadFromFile("../src/Graphics/GUI_Sprites/UI_PIC.png");
    sf::Sprite game_view(game_texture);*/


    /*
    sf::Music start_music;
    start_music.openFromFile("../src/Sounds/Music/Placeholder.ogg");
	start_music.play();
    */

   	window.clear();
	window.draw(main_menu);
	window.display();

	enum AppState {
		MainMenu,
		Game
	};

	AppState state = MainMenu;
	



	//##################
	/*if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		if (test_button.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
			bool pressed = true;
			while (pressed) {
				if (pressed) continue;
				else
				{
					std::cout << "haha" << std::endl;
					pressed = true;
					std::cout << pressed;
				}
				continue;
			}
			pressed = false;
		}
		        
    }*/
    
	
	//##################



	// The main application loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

			if (event.type == event.MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left && state == MainMenu) {
				sf::Vector2i mousePos = sf::Mouse::getPosition(window);
				if (quit_button.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
					window.close();
				}
				else if (start_button.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
					std::cout << "Start button pressed" << std::endl;
					//testsignal(window);
					state = Game;
					window.clear();
					//window.draw(game_view);
					//window.display();
					LevelLoop(window);
					window.clear();
					window.draw(main_menu);
					window.display();
					state = MainMenu;
				}
				else if (instructions_button.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
					std::cout << "Instructions button pressed" << std::endl;
				}
			}
			
			/*else if (state == Game) {
				if (event.type == event.MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
					sf::Vector2i mousePos = sf::Mouse::getPosition(window);
					if (end_game_button.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
						std::cout << "game exit button pressed" << std::endl;
						return false;
					}
					else if (button1.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
						std::cout << "button1 pressed" << std::endl;
					}
					else if (button2.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
						std::cout << "button2 pressed" << std::endl;
					}
					else if (button3.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
						std::cout << "button3 pressed" << std::endl;
					}
					else if (button4.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
						std::cout << "button4 pressed" << std::endl;
					}
					else if (button5.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
						std::cout << "button5 pressed" << std::endl;
					}
					else if (north.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
						std::cout << "north pressed" << std::endl;
						
					}
					else if (east.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
						std::cout << "east pressed" << std::endl;
					}
					else if (south.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
						std::cout << "south pressed" << std::endl;
					}
					else if (west.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
						std::cout << "west pressed" << std::endl;
					}
        		}
    		}*/
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

(11. Change the player tile to a storage tile, delete the level and resume loop from step 1.)

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
