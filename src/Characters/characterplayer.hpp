#include "character.hpp"
#include <vector>

//The character that represents the player on the game board.
//Moving will roll the player inventory along with the cube.
//After moving attempts to use the item on the top inventory tile
//of the player cube.


class Player : public Character {
    public:
    Player(DungeonTile* tile);

    std::vector<InventorySlot> GetInventory() const; //Returns the player inventory.

    bool DropItemFromSlot(InventorySlot inventoryslot); //Attempts to drop the item in the given inventory slot on the tile the player is standing on.
    //Returns true if successful.

    bool AddItemToSlot(Item* item); //Attempts to add the item to the first free inventory slot in the player inventory. Returns true if successful.

    bool MoveToDirection(DungeonTile* tile, const char* direction); //Moves the player to the given direction. Returns true if moving was successful.

    private:
    std::vector<InventorySlot> inventory_; //A vector of InventorySlots that are stored in the following order: TOP, N, E, W, S, BOTTOM.
};


//A class that represents one of the six slots in the player inventory. Holds an Item.
class InventorySlot {
    public:
    InventorySlot(Item* item); //Constructor.
    
    ~InventorySlot(); //Destructor, used if the player character dies.

    bool IsEmpty() const; //Returns true if the inventory slot is not holding an item.

    Item* GetItem() const; //Returns a pointer to the item in the inventory slot.

    bool AddItem(Item* item); //Attempts to add an item to the inventory slot. Returns true if successful. If the slot already has an item, returns false.

    void DropItem(); //Drops the item in the inventory slot.

    void UseItem(Character* targetcharacter); //Attempts to use the item held in the inventory slot.
    //Deletes the item from the slot if its durability reaches zero.

    private:
    Item* item_;
};