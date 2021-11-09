#include "character.hpp"
#include "../Inventory/inventoryslot.hpp"
#include <vector>

//The character that represents the player on the game board.
//Moving will roll the player inventory along with the cube.
//After moving attempts to use the item on the top inventory tile
//of the player cube.


class Player : public Character {
    public:
    Player(DungeonTile* tile);

    std::vector<InventorySlot*> GetInventory() const; //Returns the player inventory.

    bool MoveToDirection(const char* direction); //Moves the player to the given direction. Returns true if moving was successful.

    private:
    std::vector<InventorySlot*> inventory_; //A vector of InventorySlots that are stored in the following order: TOP, N, E, W, S, BOTTOM.
}