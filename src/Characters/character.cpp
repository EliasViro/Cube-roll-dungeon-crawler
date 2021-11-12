#include "character.hpp"


//Character is a class that all character-related classes inherit.
//A character represents an active entity in a room, such as the player, 
//enemies or allied characters. Holds information such as the type of
//the character (player, enemy, allied) and its health points.

Character::Character(CharacterType charactertype, int healthpoints, DungeonTile* currenttile)
    : charactertype_(charactertype), healthpoints_(healthpoints), defensepoints_(0), isstunned_(false), currenttile_(currenttile) {
        currenttile_->SetCharacter();
    }

Character::~Character() {}

CharacterType Character::GetCharacterType() const {
    return charactertype_;
}

DungeonTile* Character::GetCurrentTile() const {
    return currenttile_;
}

int Character::GetHealthPoints() const {
    return healthpoints_;
}

int Character::GetDefensePoints() const {
    return defensepoints_;
}

void Character::AddDefensePoints(int defense) {
    defensepoints_ += defense;
}

void Character::RemoveDefensePoints() {
    defensepoints_ = 0;
}

void Character::Stun() {
    isstunned_ = true;
}

void Character::UnStun() {
    isstunned_ = false;
}

bool Character::MoveToDirection(const char* direction) {
    if (currenttile_->GetTileNeighbor(direction)->IsPassable()) {
        currenttile_->GetTileNeighbor(direction)->SetCharacter();
        currenttile_->RemoveCharacter();
        currenttile_ = currenttile_->GetTileNeighbor(direction);
        return true;
    }
    else {
        return false;
    }
}

void Character::MoveToTile(DungeonTile* tile) {
    currenttile_ = tile;
}