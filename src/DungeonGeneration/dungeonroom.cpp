#include "dungeonroom.hpp"
#include <sstream>
#include <fstream>
#include <stdlib.h> //For randomization purposes.
#include <time.h> //For creating a random seed.
#include <string>
#include <algorithm> //For mirroring rooms horizontally.
#include <utility>

//Represents a room of a level.
//A room consists of 256 tiles on a 16 x 16 grid.

DungeonRoom::DungeonRoom(std::pair<int,int> indexinlevel, unsigned int depth, RoomType roomtype, DoorOrientation doororientation, unsigned int enemyamount, Item* loot, bool isplayerstartingroom)
    : indexinlevel_(indexinlevel), depth_(depth), hasbeenexplored_(isplayerstartingroom), loot_(loot), enemyamount_(enemyamount) {
        enemyvector_ = std::vector<Character>;
        srand(time(NULL));
        std::ifstream reader(RandomizeFileName(roomtype) + ".txt");
        std::string readline;
        std::vector<std::string> roomvector;
        while (std::getline(reader, readline)) {
            std::istringstream iss(readline);
            roomvector += readline;
        }
        std::vector<std::string> randomizedroom = RandomizeRoom(roomvector, doororientation);
        alltiles_ = CreateTiles(roomvector, isplayerstartingroom);
    }

void DungeonRoom::SpawnEnemies(std::vector<EnemyType> enemyvector) {
    int spawnedenemies = 0;
    if (!hasbeenexplored_) {
        for (auto j : alltiles_) {
            if (spawnedenemies >= enemyvector.size()) {
                break;
            }
            for (auto i : j) {
                if (i->tiletype_ == Spawner) {
                    i.SetCharacter();
                    enemyvector_.push_back(new Enemy(enemyvector[spawnedenemies], i));
                    spawnedenemies++;
                }
            }
        }
    }
}

void DungeonRoom::SpawnLoot() {
    if (loot_ != nullptr) {
        for (auto j : alltiles_) {
            for (auto i : j) {
                if (i->tiletype_ == LootTile) {
                    i->PlaceItem(loot_);
                }
            }
        }
    }
}

void DungeonRoom::CloseDoors() {
    if (alltiles_[0][7]->GetTileType() == Door && alltiles_[0][8]->GetTileType() == Door) {
        alltiles_[0][7]->Close();
        alltiles_[0][8]->Close();
    }
    if (alltiles_[15][7]->GetTileType() == Door && alltiles_[15][8]->GetTileType() == Door) {
        alltiles_[15][7]->Close();
        alltiles_[15][8]->Close();
    }
    if (alltiles_[7][0]->GetTileType() == Door && alltiles_[8][0]->GetTileType() == Door) {
        alltiles_[7][0]->Close();
        alltiles_[8][0]->Close();
    }
    if (alltiles_[7][15]->GetTileType() == Door && alltiles_[8][15]->GetTileType() == Door) {
        alltiles_[7][15]->Close();
        alltiles_[8][15]->Close();
    }
    hasbeenexplored_ = true;
}

void DungeonRoom::OpenDoors() {
    SpawnLoot();
    if (alltiles_[0][7]->GetTileType() == Door && alltiles_[0][8]->GetTileType() == Door) {
        alltiles_[0][7]->Open();
        alltiles_[0][8]->Open();
    }
    if (alltiles_[15][7]->GetTileType() == Door && alltiles_[15][8]->GetTileType() == Door) {
        alltiles_[15][7]->Open();
        alltiles_[15][8]->Open();
    }
    if (alltiles_[7][0]->GetTileType() == Door && alltiles_[8][0]->GetTileType() == Door) {
        alltiles_[7][0]->Open();
        alltiles_[8][0]->Open();
    }
    if (alltiles_[7][15]->GetTileType() == Door && alltiles_[8][15]->GetTileType() == Door) {
        alltiles_[7][15]->Open();
        alltiles_[8][15]->Open();
    }
}

std::vector<DungeonRoom> GetNeighbors() const {
        return neighbors_;
}

std::vector<DungeonRoom*> AddNeighbor(DungeonRoom* room) {
    neighbors_.push_back(room);
}

//Randomizes the name of the file in order to allow reading a random room file.
std::string RandomizeFileName(RoomType roomtype) {
    std::string filename = "RoomStorage/";
    unsigned int randomnumber = 0;
    if (roomtype == _1DoorRoom) {
        filename += "1DoorRooms/";
        randomnumber = rand() % 20 + 1; //Random number between 1 and 20
        filename += std::to_string(randomnumber); //Attach the random number to the file name
    }
    else if (roomtype == _2DoorRoomCorner) {
        filename += "2DoorRoomsCorner/";
        randomnumber = rand() % 20 + 1; //Random number between 1 and 20
        filename += std::to_string(randomnumber); //Attach the random number to the file name
    }
    else if (roomtype == _2DoorRoomOpposite) {
        filename += "2DoorRoomsOpposite/";
        randomnumber = rand() % 20 + 1; //Random number between 1 and 20
        filename += std::to_string(randomnumber); //Attach the random number to the file name
    }
    else if (roomtype == _3DoorRoom) {
        filename += "3DoorRooms/";
        randomnumber = rand() % 20 + 1; //Random number between 1 and 20
        filename += std::to_string(randomnumber); //Attach the random number to the file name
    }
    else {
        filename += "4DoorRooms/1"; //There will be only one type of four door rooms.
    }
    return filename;
}

//Mirrors the contents given as the parameter vertically.
std::vector<std::string> MirrorRoomVertically(std::vector<std::string> roomvector) {
    std::vector<std::string> roomvector2;
    for (int i = 15; i >= 0; i--) {
        roomvector2 += roomvector[i];
    }
    return roomvector2;
}

//Mirrors the contents given as the parameter horizontally.
std::vector<std::string> MirrorRoomHorizontally(std::vector<std::string> roomvector) {
    for (int j = 0; j < 16; j++) {
        for (int i = 0; i < 16 / 2; i++) {
            swap(roomvector[j][i], roomvector[j][15 - i]);
        }
    }
    return roomvector;
}

//Rotates the contents of the vector clockwise.
std::vector<std::string> RotateRoomClockwise(std::vector<std::string> roomvector) {
    std::vector<std::string> roomvector2 = roomvector;
    for (int j = 0; j < 16; j++) {
        for (int i = 15; i >= 0; i--) {
            roomvector2[j][15 - i] = roomvector[i][j];
        }
    }
    return roomvector2;
}

std::pair<std::vector<std::string>, DoorOrientation> RandomizeRoom(std::vector<std::string> roomvector, DoorOrientation doororientation) {
    if (doororientation == East || doororientation == SouthEast || doororientation == Horizontal) {
        roomvector = RotateRoomClockWise;
    }
    if (doororientation == South || doororientation == SouthWest) {
        roomvector = RotateRoomClockWise;
        roomvector = RotateRoomClockWise;
    }
    if (doororientation == West || doororientation == NorthWest) {
        roomvector = RotateRoomClockWise;
        roomvector = RotateRoomClockWise;
        roomvector = RotateRoomClockWise;
    }
    unsigned int randomnumber = rand() % 2; //Random number that is either 1 or 0.
    if (randomnumber == 1) { //Mirror the room vertically with 50% probability.
        roomvector = MirrorRoomVertically(roomvector);
        if (doororientation == NorthEast || doororientation == SouthWest) {
            roomvector = RotateRoomClockwise(roomvector);
            roomvector = RotateRoomClockwise(roomvector);
            roomvector = RotateRoomClockwise(roomvector);
        }
        if (doororientation == SouthEast || doororientation == NorthWest) {
            roomvector = RotateRoomClockwise(roomvector);
        }
        if (doororientation == North || doororientation == South) {
            roomvector = RotateRoomClockwise(roomvector);
            roomvector = RotateRoomClockwise(roomvector);
        }
    }

    unsigned int randomnumber = rand() % 2; //Random number that is either 1 or 0.
    if (randomnumber == 1) { //Mirror the room horizontally with 50% probability.
        roomvector = MirrorRoomHorizontally(roomvector);
        if (doororientation == NorthWest || doororientation == SouthEast) {
            roomvector = RotateRoomClockwise(roomvector);
            roomvector = RotateRoomClockwise(roomvector);
            roomvector = RotateRoomClockwise(roomvector);
        }
        if (doororientation == NorthEast || doororientation == SouthWest) {
            roomvector = RotateRoomClockwise(roomvector);
        }
        if (doororientation == East || doororientation == West) {
            roomvector = RotateRoomClockwise(roomvector);
            roomvector = RotateRoomClockwise(roomvector);
        }
    }
    return roomvector;
}

std::vector<DungeonTile*> CreateTiles(std::vector<std::string> roomvector, bool isplayerstartingroom) {
    std::vector<std::vector<DungeonTile*>> tilevector;
    for (int j = 0; j < 16; j++) {
        for (int i = 0; i < 16; i++) {
            if (roomvector[j][i] == '#') {
                tilevector[j][i] = new WallTile(j, i);
            }
            else if (roomvector[j][i] == '*') {
                tilevector[j][i] = new FloorTile(j, i);
            }
            else if (roomvector[j][i] == '+') {
                tilevector[j][i] = new PitTile(j, i);
            }
            else if (roomvector[j][i] == '=') {
                tilevector[j][i] = new DoorTile(j, i);
            }
            else if (roomvector[j][i] == 'E') {
                tilevector[j][i] = new EnemyTile(j, i);
            }
            else if (roomvector[j][i] == 'T') {
                tilevector[j][i] = new TrapTile(j, i);
            }
            else if (roomvector[j][i] == 'U') {
                if (isplayerstartingroom) {
                    tilevector[j][i] = new LevelEntrance(j, i);
                }
                else {
                    tilevector[j][i] = new FloorTile(j, i);
                }
            }
            else if (roomvector[j][i] == 'L') {
                tilevector[j][i] = new LootTile(j, i);
            }
            else {
                tilevector[j][i] = new LevelExit(j, i);
            }
        }
    }
    return tilevector;
}