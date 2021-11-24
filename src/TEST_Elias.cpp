
#include "../DungeonGeneration/dungeonlevel.hpp"
#include "../DungeonGeneration/dungeonroom.hpp"
#include "../Characters/characterplayer.hpp"
#include "../Characters/enemy.hpp"
#include <iostream>

/*
void PrintTiles(std::vector<std::vector<DungeonTile*>> roomvec, std::vector<Character*> enemyvec, Character* player) {
    for (auto i : roomvec) {
        for (auto j : i) {
            if (j->HasCharacter()) {
                for (auto enemy : enemyvec) {
                    if (enemy != nullptr) {
                        if (enemy->GetCurrentTile() != nullptr) {
                            if (enemy->GetCurrentTile()->GetXCoord() == j->GetXCoord() && enemy->GetCurrentTile()->GetYCoord() == j->GetYCoord()) {
                                if (enemy->GetCurrentAction() == Ranged_1 || enemy->GetCurrentAction() == Ranged_2 || enemy->GetCurrentAction() == Ranged_3) {
                                    std::cout << "R";
                                }
                                else {
                                    std::cout << "O";
                                }
                            }
                        }
                    }
                }
                if (player->GetCurrentTile() == j) {
                    std::cout << "X";
                }
            }
            else if (j->GetItem() != nullptr) {
                std::cout << "%";
            }
            else if (j->GetTileType() == Wall) {
                std::cout << "#";
            }
            else if (j->GetTileType() == Floor) {
                std::cout << "*";
            }
            else if (j->GetTileType() == Pit) {
                std::cout << "+";
            }
            else if (j->GetTileType() == Door) {
                if (j->IsOpen()) {
                    std::cout << "-";
                }
                else {
                    std::cout << "=";
                }
            }
            else if (j->GetTileType() == Spawner) {
                std::cout << "E";
            }
            else if (j->GetTileType() == Trap) {
                std::cout << "T";
            }
            else if (j->GetTileType() == Entrance) {
                std::cout << "U";
            }
            else if (j->GetTileType() == Loot) {
                std::cout << "L";
            }
            else {
                std::cout << "D";
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    if (player != nullptr) {
        std::cout << " PLAYER HP: " << player->GetHealthPoints();
    }
    std::cout << std::endl;
}

int main() {
    int sidelength = 3;
    DungeonLevel* level = new DungeonLevel(sidelength);
    Item* testitem = nullptr;
    std::vector<std::vector<DungeonTile *>> alltiles;
    std::vector<Character*> enemyvec = {nullptr, nullptr, nullptr, nullptr, nullptr};
    Character* player = nullptr;
    auto levelroomvec = level->GetRooms();
    for (auto vec : levelroomvec) {
        for (auto room : vec) {
            PrintTiles(room->GetAllTiles(), enemyvec, player);
        }
    }

    std::cout << "Test done." << std::endl;

    return 1;
}

/*
int main() {

    Item* testitem = nullptr;
    DungeonRoom* testroom = new DungeonRoom(std::make_pair(0,0), RoomType::_1DoorRoom, DoorOrientation::South, testitem, false);
    auto alltiles = testroom->GetAllTiles();
    std::vector<Character*> enemyvec = {new SpitterSpider(nullptr), new SpitterSpider(nullptr), new SpitterSpider(nullptr), new SpitterSpider(nullptr), new SpitterSpider(nullptr)};
    //std::vector<Character*> enemyvec = {new Spider(nullptr), new Spider(nullptr), new Spider(nullptr), new Spider(nullptr), new Spider(nullptr)};
    //std::vector<Character*> enemyvec = {new SpitterSpider(nullptr), nullptr, nullptr, nullptr, nullptr};
    auto player = new Player(alltiles[5][5]);
    testroom->SpawnEnemies(enemyvec);
    for (int i = 0; i < 20; i++) {
        for (auto h : enemyvec) {
            if (h != nullptr) {
                h->TakeAction(player, 1);
                PrintTiles(alltiles, enemyvec, player);
            }
        }
    }
    PrintTiles(alltiles, enemyvec, player);

    std::cout << "Test done." << std::endl;

    return 1;
}





void PrintEnemies(std::vector<Character*> enemyvec) {

    //Create all sprites

    int x_orig = 65;
    int y_orig = 67;

    for (auto enemy : enemyvec) {
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

void PrintTrapTiles(std::vector<DungeonTile*> traptiles) {
    for (auto traptile : traptiles) {
        int xcoord = traptile->GetXCoord();
        int ycoord = traptile->GetYCoord();
        if (traptile->GetTrapState() == Dormant) {
            //Print the trap with its spikes down
        }
        else if (traptile->GetTrapState() == Emerging) {
            //Print the trap with its spikes emerging
        }
        else {
            //Print the trap with its spikes up
        }
    }
}
*/


//#####################################################################################################
/*
This function holds a game loop for one room in a dungeon.

bool Level(sf::RenderWindow& window, DungeonLevel level, int depth, Character* player, std::vector<std::vector<Item*>> lootvector) {
	std::vector<std::vector<DungeonRoom*>> rooms = level.GetRooms();
	DungeonRoom* currentroom = rooms[level.GetStartPos().first][level.GetStartPos().second];
    bool lootgiven = false;
    int randomnumberx = rand() % (level.GetSideLength()); //Random number for loot placement
    int randomnumbery = rand() % (level.GetSideLength()); //Random number for loot placement
    for (auto loot : lootvector[depth]) { //Give random rooms loot.
        while (!lootgiven) {
            randomnumberx = rand() % (level.GetSideLength());
            randomnumbery = rand() % (level.GetSideLength());
            if (rooms[randomnumberx][randomnumbery]->GetIndexInLevel() != currentroom->GetIndexInLevel() && rooms[randomnumberx][randomnumbery].GetLootItem() == nullptr) {
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
	RenderScreen(window, currentroom->GetAllTiles(), false, enemyvector, player, depth, combat);
    //ASK FOR PLAYER INPUT

    //After moving, check if the player is on a door tile. This will move the player to the next room in that direction.
    if (player->GetCurrenttile() == currentroom->GetAllTiles()[0][5] || player->GetCurrenttile() == currentroom->GetAllTiles()[0][6] ||
    player->GetCurrenttile() == currentroom->GetAllTiles()[11][5] || player->GetCurrenttile() == currentroom->GetAllTiles()[11][6] ||
    player->GetCurrenttile() == currentroom->GetAllTiles()[5][11] || player->GetCurrenttile() == currentroom->GetAllTiles()[6][11] ||
    player->GetCurrenttile() == currentroom->GetAllTiles()[5][0] || player->GetCurrenttile() == currentroom->GetAllTiles()[6][0]) {
        if (player->GetCurrenttile() == currentroom->GetAllTiles()[0][5]) {
            player->MoveToTile(currentroom->GetNeighbors()[2]->GetAllTiles()[10][5]);
            currentroom = currentroom->GetNeighbors()[2];
        }
        if (player->GetCurrenttile() == currentroom->GetAllTiles()[0][6]) {
            player->MoveToTile(currentroom->GetNeighbors()[2]->GetAllTiles()[10][6]);
            currentroom = currentroom->GetNeighbors()[2];
        }
        if (player->GetCurrenttile() == currentroom->GetAllTiles()[11][5]) {
            player->MoveToTile(currentroom->GetNeighbors()[1]->GetAllTiles()[1][5]);
            currentroom = currentroom->GetNeighbors()[1];
        }
        if (player->GetCurrenttile() == currentroom->GetAllTiles()[11][6]) {
            player->MoveToTile(currentroom->GetNeighbors()[1]->GetAllTiles()[1][6]);
            currentroom = currentroom->GetNeighbors()[1];
        }
        if (player->GetCurrenttile() == currentroom->GetAllTiles()[5][11]) {
            player->MoveToTile(currentroom->GetNeighbors()[4]->GetAllTiles()[5][1]);
            currentroom = currentroom->GetNeighbors()[4];
        }
        if (player->GetCurrenttile() == currentroom->GetAllTiles()[6][11]) {
            player->MoveToTile(currentroom->GetNeighbors()[4]->GetAllTiles()[6][1]);
            currentroom = currentroom->GetNeighbors()[4];
        }
        if (player->GetCurrenttile() == currentroom->GetAllTiles()[5][0]) {
            player->MoveToTile(currentroom->GetNeighbors()[0]->GetAllTiles()[5][10]);
            currentroom = currentroom->GetNeighbors()[0];
        }
        if (player->GetCurrenttile() == currentroom->GetAllTiles()[6][0]) {
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
    }

    RenderScreen(window, currentroom->GetAllTiles(), false, enemyvector, player, depth, combat);
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

    RenderScreen(window, currentroom->GetAllTiles(), false, enemyvector, player, depth, combat);

    for (auto enemy : enemyvector) {
        if (enemy != nullptr) {
            if (enemy->GetHealthPoints > 0) {
                enemy->TakeAction(player);
            }
        }
    }
    
    RenderScreen(window, currentroom->GetAllTiles(), false, enemyvector, player, depth, combat);


	return true;
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
*/
/*
Main game:

1. Create the player character and a pointer to it. Remember starting items.
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