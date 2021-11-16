#pragma once


#include "../DungeonGeneration/dungeontile.hpp"
#include <string>

//Character is a class that all character-related classes inherit.
//A character represents an active entity in a room, such as the player, 
//enemies or allied characters. Holds information such as the type of
//the character (player, enemy, allied) and its health points.

enum CharacterType {
    PlayerCharacter,
    AlliedCharacter,
    EnemyCharacter
};

class Character {
    public:
    Character(CharacterType charactertype, int healthpoints, DungeonTile* currenttile); //Constructs a new character.

    CharacterType GetCharacterType() const; //Returns the character type.

    DungeonTile* GetCurrentTile() const; //Returns the tile the character is standing on.

    int GetXCoordinate() const; //Returns the X-coordinate of the character.

    int GetYCoordinate() const; //Returns the X-coordinate of the character.

    int GetHealthPoints() const; //Returns the healthpoints of the character.

    int GetDefensePoints() const; //Returns the defense points of the character.

    void AddDefensePoints(int defense); //Adds the amount of defense points given in the parameter.

    void RemoveDefensePoints(); //Sets the defense points to zero.

    virtual void TakeDamage(int damage) = 0; //Reduces healthpoints by the amount of damage minus defense points.

    void Stun(); //Stuns the character.

    void UnStun(); //Removes stunned status.

    bool MoveToDirection(const char* direction); //Attempts to move the character on the neighboring tile in the given direction. Returns true if successful.

    void MoveToTile(DungeonTile* tile); //Moves the character onto the given tile.

    virtual void MoveToTile(DungeonTile* tile, const char* direction) = 0; //Overridden by the player class.

    virtual void TakeAction() = 0; //Overridden by Allied and Enemy subclasses.
    //Causes Allies and Enemies to take an action.

    protected:
    CharacterType charactertype_; //The type of the character.
    int healthpoints_; //The health points of the character.
    int defensepoints_; //The defense points of the character from using a shield. Blocks damage.
    bool isstunned_; //Indicates if the character is stunned or not.
    DungeonTile* currenttile_; //A pointer to the tile the character is standing on.
};