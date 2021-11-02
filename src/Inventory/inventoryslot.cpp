#include "inventoryslot.hpp"

//A class that represents one of the six slots in the player inventory. Holds an Item.

InventorySlot::InventorySlot(Item* item) : item_(item) {}

InventorySlot::~InventorySlot() {}

bool InventorySlot::IsEmpty() const {
    if (item_ == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

Item* InventorySlot::GetItem() const {
    return item_;
}

bool InventorySlot::AddItem(Item* item) {
    if (IsEmpty()) {
        item_ = item;
        //TODO: REMOVE THE ITEM FROM THE TILE THE PLAYER IS ON.
        item_->PickUp();
        return true;
    }
    else {
        return false;
    }
}

bool InventorySlot::DropItem() {
    if (true/*TODO: CHECK IF THE TILE BELOW THE PLAYER DOESN'T HAVE AN ITEM AND IS A FLOOR TILE*/) {
        item_->Drop();
        //TODO: PLACE THE ITEM ON THE TILE THE PLAYER IS ON.
        item_ = nullptr;
        return true;
    }
    else {
        return false;
    }
}

void InventorySlot::UseItem() {
    if (item_->Use()) {
        if (item_->GetDurability() == 0) {
            delete(item_);
            item_ = nullptr;
        }
    }
}