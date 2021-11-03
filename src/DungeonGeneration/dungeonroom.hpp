#include "src/DungeonGeneration/DungeonTiles/dungeontile.hpp"
#include "src/DungeonGeneration/RoomStorage"
#include "src/Characters/character.hpp"
#include "src/Items/item.hpp"
#include <vector>

//Represents a room of a level.
//A room consists of 256 tiles on a 16 x 16 grid.

enum RoomType {
    1DoorRoom,
    2DoorRoomCorner,
    2DoorRoomOpposite,
    3DoorRoom,
    4DoorRoom
};

enum DoorOrientation {
    North,
    East,
    South,
    West,
    NorthEast,
    SouthEast,
    SouthWest,
    NorthWest,
    Horizontal,
    Vertical
}

class DungeonRoom {
    public:
    DungeonRoom::DungeonRoom(unsigned int indexinlevel, unsigned int depth, RoomType roomtype, DoorOrientation doororientation, unsigned int enemyamount, Item* loot, bool isplayerstartingroom);

    void SpawnEnemies(); //Spawns enemies on Enemy spawning tiles if the room hasn't been explored yet and the player enters the room.

    void SpawnLoot(); //Randomizes and spawns loot on a loot tile if the room was given loot when it was created.

    void CloseDoors(); //Closes the doors of the room until all enemies have been defeated.

    void OpenDoors(); //Opens the doors of the room when all enemies have been defeated.


    private:
    unsigned int indexinlevel_; //The index of the room in the list of Rooms on a level.
    unsigned int depth_; //The number of the level the player is on. Spawned enemies depend on this number.
    bool hasbeenexplored_; //True if the room has already been explored.
    Item* loot_; //A pointer to the loot item.
    unsigned int enemyamount_; //The amount of enemies that will spawn when the player enters the room for the first time.
    std::vector<DungeonTile*> alltiles_; //A vector that stores all tiles in the room.
};