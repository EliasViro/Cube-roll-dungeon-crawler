#include "dungeontile.hpp"

//A door tile, represented by '=' in room files.
//Unpassable when there are enemies in the same room as the player.
//When in an unpassable state, will deal 999 damage to any character that
//moves (is pushed) onto it.
//If the player character steps on a door tile outside combat, the player
//will be rolled to the next room.

class DoorTile : public DungeonTile {
    public:
    DoorTile(unsigned int xcoord, unsigned int ycoord);

    bool IsOpen() const;

    void Open();

    void Close();

    private:
    bool isopen_;
}