#include "../DungeonGeneration/dungeonroom.hpp"
#include "../Characters/characterplayer.hpp"
#include "../Characters/enemy.hpp"
#include <iostream>



void PrintTiles(std::vector<std::vector<DungeonTile*>> roomvec, std::vector<Character*> enemyvec, Character* player) {
    for (auto i : roomvec) {
        for (auto j : i) {
            if (j->HasCharacter()) {
                for (auto enemy : enemyvec) {
                    if (enemy->GetCurrentTile() != nullptr) {
                        if (enemy->GetCurrentTile()->GetXCoord() == j->GetXCoord() && enemy->GetCurrentTile()->GetYCoord() == j->GetYCoord()) {
                            std::cout << "O";
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
    std::cout << std::endl;
}

int main() {
    
    Item* testitem = nullptr;
    DungeonRoom* testroom = new DungeonRoom(std::make_pair(0,0), RoomType::_2DoorRoomCorner, DoorOrientation::SouthWest, testitem, false);
    auto alltiles = testroom->GetAllTiles();
    std::vector<Character*> enemyvec = {new Slime(nullptr), new Slime(nullptr), new Slime(nullptr), new Slime(nullptr), new Slime(nullptr)};
    
    auto player = new Player(alltiles[6][1]);
    
    PrintTiles(alltiles, enemyvec, player);
    testroom->SpawnEnemies(enemyvec);
    for (auto h : enemyvec) {
        h->TakeAction(player, 1);
    }
    PrintTiles(alltiles, enemyvec, player);
    for (auto h : enemyvec) {
        h->TakeAction(player, 1);
    }
    PrintTiles(alltiles, enemyvec, player);
    for (auto h : enemyvec) {
        h->TakeAction(player, 1);
    }
    PrintTiles(alltiles, enemyvec, player);

    std::cout << "Test done." << std::endl;

    return 1;
}
