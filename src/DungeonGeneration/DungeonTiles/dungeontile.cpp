#include "dungeontile.hpp"


//A class that is inherited by all tile types.
//Holds the following information:
//-The Character standing on it
//-The Item on it
//-If it is passable or not. A tile is passable if it isn't a wall, 
//a door tile during combat, a pit or there isn't a character standing on it.


DungeonTile::DungeonTile(bool ispassable, TileType tiletype) 
    : ispassable_(ispassable), item_(nullptr), tiletype_(tiletype) {}


bool DungeonTile::IsPassable() const {
    return ispassable_;
}

Item* DungeonTile::GetItem() const {
    return item_;
}

Character* DungeonTile::GetCharacter() const {
    return character_;
}

TileType DungeonTile::GetTileType() const {
    return tiletype_;
}