#include "doortile.hpp"

//A door tile, represented by '=' in room files.
//Unpassable when there are enemies in the same room as the player.
//When in an unpassable state, will deal 999 damage to any character that
//moves (is pushed) onto it.
//If the player character steps on a door tile outside combat, the player
//will be rolled to the next room.

DoorTile::DoorTile(unsigned int xcoord, unsigned int ycoord)
    : DungeonTile(true, Door, xcoord, ycoord), item_(nullptr), hascharacter_(false), isopen_(true) {}

void DoorTile::PlaceItem(Item* item) {
    item_ = item;
}

bool DoorTile::IsOpen() const {
    return isopen_;
}

void DoorTile::Open() {
    isopen_ = true;
    ispassable_ = true;
}

void DoorTile::Close() {
    isopen_ = false;
    ispassable_ = false;
}