#include "dungeontile.hpp"


//A class that is inherited by all tile types.


DungeonTile::DungeonTile(TileType tiletype, unsigned int xcoord, unsigned int ycoord) 
    : item_(nullptr), tiletype_(tiletype), hascharacter_(false), xcoord_(xcoord), ycoord_(ycoord) {

    if (tiletype == Wall) {
        ispassable_ = false;
        isopen_ = false;
    }
    else if (tiletype == Floor) {
        ispassable_ = true;
        isopen_ = true;
    }
    else if (tiletype == Pit) {
        ispassable_ = false;
        isopen_ = false;
    }
    else if (tiletype == Door) {
        ispassable_ = true;
        isopen_ = true;
    }
    else if (tiletype == Spawner) {
        ispassable_ = true;
        isopen_ = true;
    }
    else if (tiletype == Trap) {
        ispassable_ = true;
        isopen_ = true;
    }
    else if (tiletype == Entrance) {
        ispassable_ = true;
        isopen_ = true;
    }
    else if (tiletype == Loot) {
        ispassable_ = true;
        isopen_ = true;
    }
    else {
        ispassable_ = true;
        isopen_ = false;
    }
    

    std::vector<DungeonTile*> tileneighbors_;
}


bool DungeonTile::IsPassable() const {
    return ispassable_;
}

Item* DungeonTile::GetItem() const {
    return item_;
}

bool DungeonTile::HasCharacter() const {
    return hascharacter_;
}

unsigned int DungeonTile::GetXCoord() const {
    return xcoord_;
}

unsigned int DungeonTile::GetYCoord() const {
    return ycoord_;
}

void DungeonTile::PlaceItem(Item* item) {
    item_ = item;
}

bool DungeonTile::SetCharacter() {
    if (hascharacter_ == true) {
        return false;
    }
    else {
        hascharacter_ = true;
        ispassable_ = false;
        return true;
    }
}

void DungeonTile::RemoveCharacter() {
    hascharacter_ = false;
}

TileType DungeonTile::GetTileType() const {
    return tiletype_;
}

DungeonTile* DungeonTile::GetTileNeighbor(const char* direction) {
    if (direction == "N") {
        return tileneighbors_[0];
    }
    else if (direction == "E") {
        return tileneighbors_[1];
    }
    else if (direction == "W") {
        return tileneighbors_[2];
    }
    else {
        return tileneighbors_[3];
    }
}

void DungeonTile::SetTileNeighbors(std::vector<DungeonTile*> neighborvector) {
    tileneighbors_.push_back(neighborvector[0]);
    tileneighbors_.push_back(neighborvector[1]);
    tileneighbors_.push_back(neighborvector[2]);
    tileneighbors_.push_back(neighborvector[3]);
}


void DungeonTile::Close() {
    if (tiletype_ == Door) {
        isopen_ = false;
        ispassable_ = false;
    }
}

void DungeonTile::Open() {
    if (tiletype_ != Pit && tiletype_ != Wall && item_ == nullptr) {
        isopen_ = true;
        if (hascharacter_ == false) {
            ispassable_ = true;
        }
    }
}

bool DungeonTile::IsOpen() {
    return isopen_;
}