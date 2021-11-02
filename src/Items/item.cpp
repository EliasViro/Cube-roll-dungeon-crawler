#include "item.hpp"


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

Item::Item(std::string name, ItemType itemtype, unsigned int durability, unsigned int maxcooldown)
    : name_(name), itemtype_(itemtype), durability_(durability), maxcooldown_(maxcooldown), cooldown_(1), isactive_(false) {}

Item::~Item() {}

const std::string& Item::GetName() const {
    return name_;
}

const ItemType Item::GetItemType() const {
    return itemtype_;
}

unsigned int Item::GetDurability() const {
    return durability_;
}

unsigned int Item::GetMaxCoolDown() const {
    return maxcooldown_;
}

unsigned int Item::GetCoolDown() const {
    return cooldown_;
}

void Item::ReduceCoolDown() {
    cooldown_ --;
}

bool Item::Use() {
    if (GetCoolDown() == 0 && CanBeUsed()) {
        Trigger();
        durability_--;
        cooldown_ = maxcooldown_;
        return true;
    }
    else {
        return false;
    }
}

void Item::PickUp() {
        isactive_ = true;
}

void Item::Drop() {
    if (cooldown_ == 0) {
            cooldown_++;
        }
    isactive_ = false;
}