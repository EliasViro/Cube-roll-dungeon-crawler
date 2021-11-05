#include <string>
#include "src/Characters/character.hpp"

//Item is a class that all item type classes will inherit.
//Holds information about the durability, max cooldown and cooldown status
//of the item and its state - if it is on the ground or in the player 
//inventory. Items that are laying on the floor will not have their 
//cooldown reduced every turn, unlike items in the player inventory.
//Items that are in the top inventory slot of the player after movement
//will be called by the CharacterPlayer class and will attempt to activate
//their Use function, which will check if the requirements for using the item
//are met and the item is not on cooldown. If both of these apply, the item
//will be used and will receive cooldown status for the duration specified
//in that item's class, and its durability will be decreased by 1. If the
//durability of an item reaches zero, the item will be deleted.
//Items on the ground can be picked up if the player has room in their
//inventory, which will move the item from the ground to the first free
//inventory slot and add one point to the item's cooldown status.

enum ItemType {
    MeleeWeapon,
    RangedWeapon,
    Shield,
    Spell,
    Potion
};

class Item {
    public:
    Item(const std::string& name, ItemType itemtype, unsigned int durability, unsigned int maxcooldown); //constructs a new item.

    ~Item(); //deletes the item if the durability reaches zero.

    const std::string& GetName() const; //Returns the name of the item.

    const ItemType GetItemType() const; //Returns the type of the item.

    unsigned int GetDurability() const; //Returns the durability of the item.

    unsigned int GetMaxCoolDown() const; //Returns the max cooldown of the item.

    unsigned int GetCoolDown() const; //Returns the current cooldown of the item.

    bool IsActive() const; //Returns the status of the item. True if in player inventory.

    void ReduceCoolDown(); //Reduces the cooldown by one, but not below zero and only when the item is active.

    virtual bool CanBeUsed() const = 0; //Overridden by subclasses. Returns true if the conditions for using the item apply.

    virtual void Trigger(Character* targetcharacter) = 0; //Overridden by subclasses. Triggers the item's specific effect, such as a health potion
    //restoring player health or a sword dealing damage to an enemy.

    virtual std::string& GetDescription() const = 0; //Overridden by subclasses. Returns the description of the item.

    bool Use(Character* targetcharacter); //Triggers the item's effect if its cooldown is zero and the conditions for using it apply. 
    //Sets the cooldown to max and reduces thedurability by one. If durability reaches zero calls the destructor.
    //Returns true if using the item succeeded, false otherwise.

    void PickUp(); //Sets the isactive status to true.

    void Drop(); //Sets the isactive status to false and adds one point to the cooldown if the item isn't on cooldown.

    protected:
    std::string name_; //The name of the item.
    ItemType itemtype_; //The type of the item.
    unsigned int durability_; //The durability of the item.
    unsigned int maxcooldown_; //The maximum cooldown of the item.
    unsigned int cooldown_; //The current cooldown status of the item.
    bool isactive_; //Status of the item. True when in player inventory, false otherwise.
};