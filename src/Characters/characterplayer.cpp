#include "characterplayer.hpp"


//The character that represents the player on the game board.
//Moving will roll the player inventory along with the cube.
//After moving attempts to use the item on the top inventory tile
//of the player cube.


Player::Player(DungeonTile* tile) 
    : Character(PlayerCharacter, 3, tile) {
    inventory_ = {new InventorySlot(nullptr), new InventorySlot(nullptr), new InventorySlot(nullptr), new InventorySlot(nullptr), new InventorySlot(nullptr), new InventorySlot(nullptr)};
}

std::vector<InventorySlot*> Player::GetInventory() const {
    return inventory_;
}

bool Player::DropItemFromSlot(InventorySlot* inventoryslot) {
    if (!inventoryslot->IsEmpty() && currenttile_->GetItem() == nullptr) {
        currenttile_->PlaceItem(inventoryslot->GetItem());
        inventoryslot->DropItem();
        return true;
    }
    else {
        return false;
    }
}

bool Player::AddItemToSlot(Item* item) {
    bool hasbeenadded = false;
    int i = 0;
    while (hasbeenadded == false && i < 6) {
        hasbeenadded = inventory_[i]->AddItem(item);
        i++;
    }
    return hasbeenadded;
} //Attempts to add the item to the first free inventory slot in the player inventory. Returns true if successful.

bool Player::MoveToDirection(DungeonTile* tile, const char* direction) {
    RemoveDefensePoints();
    if (tile->IsPassable()) {
        tile->SetCharacter();
        currenttile_->RemoveCharacter();
        currenttile_ = tile;
        std::vector<InventorySlot*> tempinventory;
        tempinventory.push_back(inventory_[0]);
        tempinventory.push_back(inventory_[1]);
        tempinventory.push_back(inventory_[2]);
        tempinventory.push_back(inventory_[3]);
        tempinventory.push_back(inventory_[4]);
        tempinventory.push_back(inventory_[5]);
        
        if (direction == "N") {
            inventory_[0] = tempinventory[4];
            inventory_[1] = tempinventory[0];
            inventory_[2] = tempinventory[2];
            inventory_[3] = tempinventory[3];
            inventory_[4] = tempinventory[5];
            inventory_[5] = tempinventory[1];
        }
        else if (direction == "E") {
            inventory_[0] = tempinventory[2];
            inventory_[1] = tempinventory[1];
            inventory_[2] = tempinventory[0];
            inventory_[3] = tempinventory[5];
            inventory_[4] = tempinventory[4];
            inventory_[5] = tempinventory[3];
        }
        else if (direction == "W") {
            inventory_[0] = tempinventory[3];
            inventory_[1] = tempinventory[4];
            inventory_[2] = tempinventory[5];
            inventory_[3] = tempinventory[0];
            inventory_[4] = tempinventory[1];
            inventory_[5] = tempinventory[2];
        }
        else {
            inventory_[0] = tempinventory[1];
            inventory_[1] = tempinventory[5];
            inventory_[2] = tempinventory[2];
            inventory_[3] = tempinventory[3];
            inventory_[4] = tempinventory[0];
            inventory_[5] = tempinventory[4];
        }
        inventory_[0]->UseItem();
        return true;
    }
    else {
        return false;
    }
}

void Player::TakeDamage(int damage) {
    if (inventory_[0]->GetItem()->GetItemType() == ShieldItem) {
        AddDefensePoints(inventory_[0]->UseItem());
    }
    healthpoints_ = healthpoints_ - (damage - defensepoints_);
}


//A class that represents one of the six slots in the player inventory. Holds an Item.

InventorySlot::InventorySlot(Item* item) : item_(item) {}

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

int InventorySlot::UseItem() {
    if (item_->Use()) {
        if (item_->GetDurability() == 0) {
            delete(item_);
            item_ = nullptr;
        }
    }
}