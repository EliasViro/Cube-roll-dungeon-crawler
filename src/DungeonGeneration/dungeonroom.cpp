#include "dungeonroom.hpp"
#include <sstream>
#include <fstream>
#include <stdlib.h> //For randomization purposes.
#include <time.h> //For creating a random seed.
#include <string>
#include <algorithm> //For mirroring rooms horizontally.
#include <utility>

//Represents a room of a level.
//A room consists of 144 tiles on a 12 x 12 grid.

DungeonRoom::DungeonRoom(std::pair<int,int> indexinlevel, unsigned int depth, RoomType roomtype, DoorOrientation doororientation, Item* loot, bool isplayerstartingroom)
    : indexinlevel_(indexinlevel), depth_(depth), hasbeenexplored_(isplayerstartingroom), loot_(loot) {
        srand(time(NULL));
        std::vector<DungeonRoom*> neighbors_;
        std::ifstream reader(RandomizeFileName(roomtype) + ".txt");
        std::string readline;
        std::vector<std::string&> roomvector;
        while (std::getline(reader, readline)) {
            std::istringstream iss(readline);
            roomvector.push_back(readline);
        }
        roomvector = RandomizeRoom(roomvector, doororientation);
        alltiles_ = CreateTiles(roomvector, isplayerstartingroom);
    }

std::pair<int,int> DungeonRoom::GetIndexInLevel() const {
    return indexinlevel_;
}

DungeonTile* DungeonRoom::GetDungeonTile(int xcoord, int ycoord) const {
    return alltiles_[xcoord][ycoord];
}

std::vector<std::vector<DungeonTile*>> DungeonRoom::GetAllTiles() const {
    return alltiles_;
}

void DungeonRoom::SpawnEnemies(std::vector<Character*> enemyvector) {
    int spawnedenemies = 0;
    if (!hasbeenexplored_) {
        for (auto j : alltiles_) {
            if (spawnedenemies >= enemyvector.size()) {
                break;
            }
            for (auto i : j) {
                if (i->GetTileType() == Spawner) {
                    i->SetCharacter();
                    enemyvector[spawnedenemies]->MoveToTile(i);
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
                if (i->GetTileType() == Loot) {
                    i->PlaceItem(loot_);
                }
            }
        }
    }
}

void DungeonRoom::CloseDoors() {
    alltiles_[0][5]->Close();
    alltiles_[0][6]->Close();
    alltiles_[11][5]->Close();
    alltiles_[11][6]->Close();
    alltiles_[5][0]->Close();
    alltiles_[6][0]->Close();
    alltiles_[5][11]->Close();
    alltiles_[6][11]->Close();
    hasbeenexplored_ = true;
}

void DungeonRoom::OpenDoors() {
    SpawnLoot();
    alltiles_[0][5]->Open();
    alltiles_[0][6]->Open();
    alltiles_[11][5]->Open();
    alltiles_[11][6]->Open();
    alltiles_[5][0]->Open();
    alltiles_[6][0]->Open();
    alltiles_[5][11]->Open();
    alltiles_[6][11]->Open();
}

std::vector<DungeonRoom*> DungeonRoom::GetNeighbors() const {
        return neighbors_;
}

void DungeonRoom::AddNeighbor(DungeonRoom* room) {
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
std::vector<std::string&> MirrorRoomVertically(std::vector<std::string&> roomvector) {
    std::vector<std::string&> roomvector2;
    for (int i = 11; i >= 0; i--) {
        roomvector2.push_back(roomvector[i]);
    }
    return roomvector2;
}

//Mirrors the contents given as the parameter horizontally.
std::vector<std::string&> MirrorRoomHorizontally(std::vector<std::string&> roomvector) {
    for (int j = 0; j < 12; j++) {
        for (int i = 0; i < 12 / 2; i++) {
            std::swap(roomvector[j][i], roomvector[j][15 - i]);
        }
    }
    return roomvector;
}

//Rotates the contents of the vector clockwise.
std::vector<std::string&> RotateRoomClockwise(std::vector<std::string&> roomvector) {
    std::vector<std::string&> roomvector2 = roomvector;
    for (int j = 0; j < 12; j++) {
        for (int i = 15; i >= 0; i--) {
            roomvector2[j][11 - i] = roomvector[i][j];
        }
    }
    return roomvector2;
}

std::vector<std::string&> RandomizeRoom(std::vector<std::string&> roomvector, DoorOrientation doororientation) {
    if (doororientation == East || doororientation == SouthEast || doororientation == Horizontal) {
        roomvector = RotateRoomClockwise(roomvector);
    }
    if (doororientation == South || doororientation == SouthWest) {
        roomvector = RotateRoomClockwise(roomvector);
        roomvector = RotateRoomClockwise(roomvector);
    }
    if (doororientation == West || doororientation == NorthWest) {
        roomvector = RotateRoomClockwise(roomvector);
        roomvector = RotateRoomClockwise(roomvector);
        roomvector = RotateRoomClockwise(roomvector);
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

std::vector<std::vector<DungeonTile*>> CreateTiles(std::vector<std::string&> roomvector, bool isplayerstartingroom) {
    std::vector<std::vector<DungeonTile*>> tilevector;
    std::vector<DungeonTile*> neighborvector;
    for (int j = 0; j < 12; j++) {
        for (int i = 0; i < 12; i++) {
            if (roomvector[j][i] == '#') {
                tilevector[j][i] = new DungeonTile(Wall, j, i);
            }
            else if (roomvector[j][i] == '*') {
                tilevector[j][i] = new DungeonTile(Floor, j, i);
            }
            else if (roomvector[j][i] == '+') {
                tilevector[j][i] = new DungeonTile(Pit, j, i);
            }
            else if (roomvector[j][i] == '=') {
                tilevector[j][i] = new DungeonTile(Door, j, i);
            }
            else if (roomvector[j][i] == 'E') {
                tilevector[j][i] = new DungeonTile(Spawner, j, i);
            }
            else if (roomvector[j][i] == 'T') {
                tilevector[j][i] = new DungeonTile(Trap, j, i);
            }
            else if (roomvector[j][i] == 'U') {
                if (isplayerstartingroom) {
                    tilevector[j][i] = new DungeonTile(Entrance, j, i);
                }
                else {
                    tilevector[j][i] = new DungeonTile(Floor, j, i);
                }
            }
            else if (roomvector[j][i] == 'L') {
                tilevector[j][i] = new DungeonTile(Loot, j, i);
            }
            else {
                tilevector[j][i] = new DungeonTile(Exit, j, i);
            }
        }
    }
    for (int a = 0; a < 12; a++) {
        for (int b = 0; b < 12; b++) {
            if (b - 1 >= 0) { //North neighbor
                neighborvector.push_back(tilevector[a][b - 1]);
            }
            else {
                neighborvector.push_back(nullptr);
            }
            if (a + 1 <= 11) { //East neighbor
                neighborvector.push_back(tilevector[a + 1][b]);
            }
            else {
                neighborvector.push_back(nullptr);
            }
            if (a - 1 >= 0) { //West neighbor
                neighborvector.push_back(tilevector[a - 1][b]);
            }
            else {
                neighborvector.push_back(nullptr);
            }
            if (b + 1 <= 11) { //South neighbor
                neighborvector.push_back(tilevector[a][b + 1]);
            }
            else {
                neighborvector.push_back(nullptr);
            }
            tilevector[a][b]->SetTileNeighbors(neighborvector);
            neighborvector.pop_back();
            neighborvector.pop_back();
            neighborvector.pop_back();
            neighborvector.pop_back();
        }
    }
    return tilevector;
}