#include "../Items/item.hpp"


//A class that is inherited by all tile types.

enum TileType {
    Floor,
    Wall,
    Pit,
    Door,
    Trap,
    Spawner,
    Exit,
    Entrance,
    Loot
};

class DungeonTile {
    public:
    DungeonTile(TileType tiletype, unsigned int xcoord, unsigned int ycoord); //Constructs a new tile.

    ~DungeonTile(); //Destructor.

    bool IsPassable() const; //Returns true if the tile can be walked onto.

    Item* GetItem() const; //Returns a pointer to the item on the tile.

    bool HasCharacter() const; //Returns true if there is a character standing on the tile.

    unsigned int GetXCoord() const; //Returns the X-coordinate of the tile.

    unsigned int GetYCoord() const; //Returns the Y-coordinate of the tile.

    virtual void PlaceItem(Item* item) = 0; //Overridden by subclasses. Places an item on the tile.

    bool SetCharacter(); //Informs the tile that a Character has stepped into it.
    //Returns true if setting the character was successful, false if there already was a character on the tile.

    void RemoveCharacter(); //Informs the tile that a Character has left it.

    TileType GetTileType() const; //Returns the type of the tile.

    protected:
    bool ispassable_; //The status of the tile. True if passable, false otherwise.
    Item* item_; //The item on the tile.
    bool hascharacter_; //Tells if there is a Character on the tile or not.
    TileType tiletype_; //The type of the tile, e.g. FloorTile or WallTile.
    unsigned int xcoord_; //The x-coordinate of the tile in a room.
    unsigned int ycoord_; //The y-coordinate of the tile in a room.
};