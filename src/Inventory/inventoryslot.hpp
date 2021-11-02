#include "src/Items/item.hpp"

//A class that represents one of the six slots in the player inventory. Holds an Item.

class InventorySlot {
    public:
    InventorySlot(Item* item); //Constructor.
    
    ~InventorySlot(); //Destructor, used if the player character dies.

    bool HasItem() const; //Returns true if the inventory slot is holding an item.

    void AddItem(); //Adds an item to the inventory slot.

    void DropItem(); //Attempts the item in the inventory slot.

    void UseItem(); //Attempts to use the item held in the inventory slot.
    //Deletes the item from the slot if its durability reaches zero.

    private:
    Item* item_;
};