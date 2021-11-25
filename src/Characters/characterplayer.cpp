#include "characterplayer.hpp"



//The character that represents the player on the game board.
//Moving will roll the player inventory along with the cube.
//After moving attempts to use the item on the top inventory tile
//of the player cube.

Player::Player(DungeonTile* tile) 
    : Character(PlayerCharacter, 4, tile) {
    inventory_ = {new InventorySlot(nullptr), new InventorySlot(nullptr), new InventorySlot(nullptr), new InventorySlot(nullptr), new InventorySlot(nullptr), new InventorySlot(nullptr)};
    if (tile != nullptr) {
        tile->SetCharacter();
    }
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

int Player::MoveToDirection(std::string direction) {
    if (currenttile_->GetTileNeighbor(direction)->IsPassable()) {
        RemoveDefensePoints();
        currenttile_->GetTileNeighbor(direction)->SetCharacter();
        currenttile_->RemoveCharacter();
        currenttile_ = currenttile_->GetTileNeighbor(direction);
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
        auto itemintopslot = inventory_[0]->GetItem();
        int itemreturnval = 0;
        if (itemintopslot != nullptr) {
            if (itemintopslot->GetName() == "Potion of healing" && healthpoints_ < 4) {
                itemreturnval = itemintopslot->Use();
                if (itemreturnval > 0) {
                    healthpoints_++;
                }
            }
            bool itemoncooldown = false;
            for (auto slot : inventory_) {
                if (!slot->IsEmpty()) {
                    if (slot->GetItem()->GetCoolDown() >= 0) {
                        itemoncooldown = true;
                        break;
                    }
                }
            }
            if (itemintopslot->GetName() == "Potion of stamina" && itemoncooldown) {
                itemreturnval = itemintopslot->Use();
                if (itemreturnval > 0) {
                    for (auto slot2 : inventory_) {
                        if (!slot2->IsEmpty()) {
                            while (slot2->GetItem()->GetCoolDown() > 0) {
                                slot2->GetItem()->ReduceCoolDown();
                            }
                        }
                    }
                }
            }
            if (itemintopslot->GetItemType() == RangedWeaponItem) {
                itemreturnval = 10;
            }
            if (itemintopslot->GetItemType() == MeleeWeaponItem) {
                if (currenttile_->GetTileNeighbor("N")->HasCharacter() || currenttile_->GetTileNeighbor("E")->HasCharacter() || currenttile_->GetTileNeighbor("W")->HasCharacter() || currenttile_->GetTileNeighbor("S")->HasCharacter()) {
                    itemreturnval = itemintopslot->Use();
                }
            }
            for (auto slot3 : inventory_) {
                if (!slot3->IsEmpty()) {
                    slot3->GetItem()->ReduceCoolDown();
                }
            }
        }
        if (currenttile_->GetTrapState() == Emerging) {
            TakeDamage(1);
        }
        return itemreturnval;
    }
    else {
        return -1;
    }
}

void Player::TakeDamage(int damage) {
    if (!inventory_[0]->IsEmpty()) {
        if (inventory_[0]->GetItem()->GetItemType() == ShieldItem) {
            AddDefensePoints(inventory_[0]->UseItem());
        }
    }
    healthpoints_ = healthpoints_ - (damage - defensepoints_);
}

void Player::TakeAction(Character* targetcharacter, int damage) {
    if (!inventory_[0]->IsEmpty()) {
        targetcharacter->TakeDamage(damage);
        if (inventory_[0]->GetItem()->GetItemType() == MeleeWeaponItem || inventory_[0]->GetItem()->GetItemType() == RangedWeaponItem) {
            if (inventory_[0]->GetItem()->IsStunning()) {
                targetcharacter->Stun(2);
            }
        }
    }
}