#include "character.hpp"


//Character is a class that all character-related classes inherit.
//A character represents an active entity in a room, such as the player, 
//enemies or allied characters. Holds information such as the type of
//the character (player, enemy, allied) and its health points.

Character::Character(CharacterType charactertype, int healthpoints, DungeonTile* currenttile)
    : charactertype_(charactertype), healthpoints_(healthpoints), defensepoints_(0), currenttile_(currenttile) {
        currenttile_->SetCharacter();
    }

Character::~Character() {}

CharacterType Character::GetCharacterType() const {
    return charactertype_;
}

int Character::GetHealthPoints() const {
    return healthpoints_;
}

void Character::TakeDamage(int damage) {
    healthpoints_ = healthpoints_ - (damage - defensepoints_);
    if (healthpoints_ <= 0) {
        delete(this);
    }
}

bool MoveToDirection(const char* direction) {
    if (currenttile_->GetTileInDirection(direction).IsPassable()) {
        currenttile_->GetTileInDirection(direction).SetCharacter();
        currenttile_->RemoveCharacter();
        currenttile_ = currenttile_->GetTileInDirection(direction);
        return true;
    }
    else {
        return false;
    }
}