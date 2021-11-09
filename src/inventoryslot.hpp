#include "Items/item.hpp"
#include "Characters/characterplayer.hpp"
#include "DungeonGeneration/DungeonTiles/dungeontile.hpp"

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