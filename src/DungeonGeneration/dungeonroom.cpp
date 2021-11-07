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
        srand(time(NULL));
        std::ifstream reader(RandomizeFileName(roomtype) + ".txt");
        std::string readline;
        std::vector<std::string> roomvector;
        while (std::getline(reader, readline)) {
            std::istringstream iss(readline);
            roomvector += readline;
        }
        std::pair<std::vector<std::string>, DoorOrientation> randomizedroom = RandomizeRoom(roomvector, doororientation);
        doororientation_ = randomizedroom->second;
        alltiles_ = CreateTiles(roomvector);
    }

void DungeonRoom::SpawnEnemies() {
    if (!hasbeenexplored_) {
        for (auto j : alltiles_) {
            for (auto i : j) {
                if (i->tiletype_ == EnemyTile) {
                    //SPAWN AN ENEMY ON THE TILE
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

    hasbeenexplored_ = true;
} //Closes the doors of the room until all enemies have been defeated.

void DungeonRoom::OpenDoors() {
    SpawnLoot();

} //Opens the doors of the room when all enemies have been defeated.

std::vector<DungeonRoom> GetNeighbors() const {
        return neighbors_;
}

std::vector<DungeonRoom*> AddNeighbor(DungeonRoom* room) {
    neighbors_.push_back(room);
}

//Randomizes the name of the file in order to allow reading a random room file.
std::string RandomizeFileName(RoomType roomtype) {
    std::string filename = "src/DungeonGeneration/RoomStorage/";
    unsigned int randomnumber = 0;
    if (roomtype == 1DoorRoom) {
        filename += "1DoorRooms/";
        randomnumber = rand() % 20 + 1; //Random number between 1 and 20
        filename += std::to_string(randomnumber); //Attach the random number to the file name
    }
    else if (roomtype == 2DoorRoomCorner) {
        filename += "2DoorRoomsCorner/";
        randomnumber = rand() % 20 + 1; //Random number between 1 and 20
        filename += std::to_string(randomnumber); //Attach the random number to the file name
    }
    else if (roomtype == 2DoorRoomOpposite) {
        filename += "2DoorRoomsOpposite/";
        randomnumber = rand() % 20 + 1; //Random number between 1 and 20
        filename += std::to_string(randomnumber); //Attach the random number to the file name
    }
    else if (roomtype == 3DoorRoom) {
        filename += "3DoorRooms/";
        randomnumber = rand() % 20 + 1; //Random number between 1 and 20
        filename += std::to_string(randomnumber); //Attach the random number to the file name
    }
    else {
        filename += "4DoorRooms/";
        randomnumber = rand() % 20 + 1; //Random number between 1 and 20
        filename += std::to_string(randomnumber); //Attach the random number to the file name
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


DoorOrientation OrientClockwise(DoorOrientation doororientation) {
    if (doororientation == Horizontal) {
        return Vertical;
    }
    if (doororientation == Vertical) {
        return Horizontal;
    }
    unsigned int index = 0;
    if (doororientation == East || doororientation == SouthEast) {
        index = 1;
    }
    if (doororientation == South || doororientation == SouthWest) {
        index = 2;
    }
    if (doororientation == West || doororientation == NorthWest) {
        index = 3;
    }
    if (doororientation == North || doororientation == East || doororientation == South || doororientation == West) {
        std::vector<DoorOrientation> directions = {North, East, South, West};
    }
    else {
        std::vector<DoorOrientation> directions = {NorthEast, SouthEast, SouthWest, NorthWest};
    }
    if (index == 3) {
        index = 0;
    }
    else {
        index++;
    }
    return directions[index];
}

std::pair<std::vector<std::string>, DoorOrientation> RandomizeRoom(std::vector<std::string> roomvector, DoorOrientation doororientation) {
    unsigned int randomnumber = rand() % 2; //Random number that is either 1 or 0.
    if (randomnumber == 1) { //Mirror the room vertically with 50% probability.
        roomvector = MirrorRoomVertically(roomvector);
        if (doororientation == NorthEast || doororientation == SouthWest) {
            doororientation = OrientClockWise(doororientation);
            doororientation = OrientClockWise(doororientation);
            doororientation = OrientClockWise(doororientation);
            roomvector = RotateRoomClockwise(roomvector);
            roomvector = RotateRoomClockwise(roomvector);
            roomvector = RotateRoomClockwise(roomvector);
        }
        if (doororientation == North || doororientation == South) {
            doororientation = OrientClockWise(doororientation);
            doororientation = OrientClockWise(doororientation);
            roomvector = RotateRoomClockwise(roomvector);
            roomvector = RotateRoomClockwise(roomvector);
        }
    }
    unsigned int randomnumber = rand() % 2; //Random number that is either 1 or 0.
    if (randomnumber == 1) { //Mirror the room horizontally with 50% probability.
        roomvector = MirrorRoomHorizontally(roomvector);
        if (doororientation == NorthWest || doororientation == SouthEast) {
            doororientation = OrientClockWise(doororientation);
            doororientation = OrientClockWise(doororientation);
            doororientation = OrientClockWise(doororientation);
            roomvector = RotateRoomClockwise(roomvector);
            roomvector = RotateRoomClockwise(roomvector);
            roomvector = RotateRoomClockwise(roomvector);
        }
        if (doororientation == East || doororientation == West) {
            doororientation = OrientClockWise(doororientation);
            doororientation = OrientClockWise(doororientation);
            roomvector = RotateRoomClockwise(roomvector);
            roomvector = RotateRoomClockwise(roomvector);
        }
    }
    std::pair<std::vector<std::string>, DoorOrientation> returnthis;
    returnthis.first = roomvector;
    returnthis.second = doororientation;
    return returnthis;
}

std::vector<DungeonTile*> CreateTiles(std::vector<std::string> roomvector) {
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
                tilevector[j][i] = new LevelEntrance(j, i);
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