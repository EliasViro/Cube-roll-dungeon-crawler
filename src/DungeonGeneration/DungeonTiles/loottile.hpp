#include "dungeontile.hpp"


//Functions as a regular floor tile with the addition of being able to spawn loot on it when requested.

class LootTile : public DungeonTile {
    public:
    LootTile(unsigned int xcoord, unsigned int ycoord);
}