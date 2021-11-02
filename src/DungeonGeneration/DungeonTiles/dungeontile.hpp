#include "src/Items/item.hpp"
#include "src/Characters/character.hpp"


//A class that is inherited by all tile types.
//Holds the following information:
//-The Character standing on it
//-The Item on it
//-Its t
//-If it is passable or not. A tile is passable if it isn't a wall, 
//a door tile during combat, a pit or there isn't a character standing on it.

enum TileType {
    FloorTile,
    WallTile,
    PitTile,
    DoorTile,
    Traptile,
    EnemyTile,
    LevelExit
};

class DungeonTile {
    public:
    DungeonTile(bool ispassable, TileType tiletype); //Constructs a new tile.

    ~DungeonTile(); //Destructor.

    bool IsPassable() const; //Returns true if the tile can be walked onto.

    Item* GetItem() const; //Returns a pointer to the item on the tile.

    Character* GetCharacter() const; //Returns a pointer to the character standing on the tile.

    void PlaceItem(Item* item); //Places an item on the tile.

    virtual bool SetCharacter(Character* character) = 0; //Overridden by subclasses.
    //Sets the character on the tile to the one given as a parameter.
    //Returns true if setting the character was successful, false if there already was a character on the tile.

    TileType GetTileType() const; //Returns the type of the tile.

    protected:
    bool ispassable_; //The status of the tile. True if passable, false otherwise.
    Item* item_; //The item on the tile.
    Character* character_; //The Character standing on the tile.
    TileType tiletype_; //The type of the tile, e.g. FloorTile or WallTile.
};