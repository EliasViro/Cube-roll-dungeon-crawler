
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
*/