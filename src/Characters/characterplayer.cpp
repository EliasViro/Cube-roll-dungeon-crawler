#include "src/Characters/characterplayer.hpp"


//The character that represents the player on the game board.
//Moving will roll the player inventory along with the cube.
//After moving attempts to use the item on the top inventory tile
//of the player cube.


Player::Player(DungeonTile* tile) 
    : Character(PlayerCharacter, 3, tile) {
    inventory_ = {new InventorySlot(nullptr), new InventorySlot(new Shortsword), new InventorySlot(new Shortsword), new InventorySlot(nullptr), new InventorySlot(nullptr), new InventorySlot(Roundshield)}
}

std::vector<InventorySlot*> Player::GetInventory() {
    return inventory_;
}

bool Player::MoveToDirection(const char* direction) {
    if (currenttile_->GetTileInDirection(direction).IsPassable()) {
        currenttile_->GetTileInDirection(direction).SetCharacter();
        currenttile_->RemoveCharacter();
        currenttile_ = currenttile_->GetTileInDirection(direction);
        std::vector<InventorySlot*> tempinventory = inventory_;
        if (direction == 'N') {
            inventory_[0] = tempinventory[4]
            inventory_[1] = tempinventory[0]
            inventory_[2] = tempinventory[2]
            inventory_[3] = tempinventory[3]
            inventory_[4] = tempinventory[5]
            inventory_[5] = tempinventory[1]
        }
        else if (direction == 'E') {
            inventory_[0] = tempinventory[2]
            inventory_[1] = tempinventory[1]
            inventory_[2] = tempinventory[0]
            inventory_[3] = tempinventory[5]
            inventory_[4] = tempinventory[4]
            inventory_[5] = tempinventory[3]
        }
        else if (direction == 'W') {
            inventory_[0] = tempinventory[3]
            inventory_[1] = tempinventory[4]
            inventory_[2] = tempinventory[5]
            inventory_[3] = tempinventory[0]
            inventory_[4] = tempinventory[1]
            inventory_[5] = tempinventory[2]
        }
        else {
            inventory_[0] = tempinventory[1]
            inventory_[1] = tempinventory[5]
            inventory_[2] = tempinventory[2]
            inventory_[3] = tempinventory[3]
            inventory_[4] = tempinventory[0]
            inventory_[5] = tempinventory[4]
        }
        inventory_[0].UseItem();
        return true;
    }
    else {
        return false;
    }
}