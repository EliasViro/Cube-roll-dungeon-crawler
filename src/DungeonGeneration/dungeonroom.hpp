#include "DungeonTiles/dungeontile.hpp"
#include "../Characters/character.hpp"
#include "../Items/item.hpp"
#include <vector>

//Represents a room of a level.
//A room consists of 144 tiles on a 12 x 12 grid.

enum RoomType {
    _1DoorRoom,
    _2DoorRoomCorner,
    _2DoorRoomOpposite,
    _3DoorRoom,
    _4DoorRoom
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
    Vertical,
    Omni
};


class DungeonRoom {
    public:
    DungeonRoom(std::pair<int,int> indexinlevel, unsigned int depth, RoomType roomtype, DoorOrientation doororientation, Item* loot, bool isplayerstartingroom);
    
    void SpawnEnemies(std::vector <EnemyType> enemyvector); //Spawns enemies on Enemy spawning tiles if the room hasn't been explored yet and the player enters the room.

    void SpawnLoot(); //Randomizes and spawns loot on a loot tile if the room was given loot when it was created.

    void CloseDoors(); //Closes the doors of the room until all enemies have been defeated.

    void OpenDoors(); //Opens the doors of the room when all enemies have been defeated.
    
    std::vector<DungeonRoom*> GetNeighbors() const; // return the room neighbors
    
    std::vector<DungeonRoom*> AddNeighbor(DungeonRoom* room);

    private:
    std::pair<int, int> indexinlevel_; //The index of the room in the list of Rooms on a level.
    unsigned int depth_; //The number of the level the player is on. The difficulty of generated rooms is scaled based on this number.
    bool hasbeenexplored_; //True if the room has already been explored.
    Item* loot_; //A pointer to the loot item.
    std::vector<Character*> enemyvector_;
    std::vector<DungeonTile*> alltiles_; // A vector that stores all tiles in the room.
    std::vector<DungeonRoom*> neighbors_; // A Vector that stores the neighbors in the room 
};