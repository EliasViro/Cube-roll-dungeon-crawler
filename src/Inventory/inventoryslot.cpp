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
        item_->PickUp();
        return true;
    }
    else {
        return false;
    }
}

void InventorySlot::DropItem() {
    item_->Drop();
    item_ = nullptr;
}

void InventorySlot::UseItem(Character* targetcharacter) {
    if (item_->Use(targetcharacter)) {
        if (item_->GetDurability() == 0) {
            delete(item_);
            item_ = nullptr;
        }
    }
}