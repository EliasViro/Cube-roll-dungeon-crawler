#include "dungeontile.hpp"


//A pit tile, represented by 'P' in room files.
//Unpassable to all but flying enemies, and doesn't prevent ranged 
//attacks through it. 
//Deals 999 damage to any character that moves (or is pushed) onto it,
//excluding flying enemies, which are an exception and can move on 
//pit tiles and will not take damage from the tile.

class PitTile : public DungeonTile {
    public:
    PitTile(unsigned int xcoord, unsigned int ycoord);
}