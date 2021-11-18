#pragma once


#include "character.hpp"
#include <stdlib.h> //For randomization purposes.
#include <time.h> //For creating a random seed.
#include <string>

//Enemy is a class that all enemy type classes inherit. Holds information
//about the movement speed and attack damage of 
//an enemy character, its own location in a room and a vector that holds
//its action pattern that the enemy will proceed through by one every time
//it takes a turn. Enemies will randomize the step they are on in their
//action pattern when they are created.


enum EnemyAI {
    Aggressive,
    Careful,
    Random,
    Stationary
};

enum ActionType {
    Empty,
    Indirect,
    Melee_1,
    Ranged_1,
    Defend_1,
    Melee_2,
    Ranged_2,
    Defend_2,
    Melee_3,
    Ranged_3,
    Defend_3
};


class Enemy : public Character {
    public:
    Enemy(const std::string& name, const std::string& description, DungeonTile* tile, EnemyAI enemyai, std::vector<ActionType> actionvector);

    EnemyAI GetEnemyAI() const; //Returns the AI type of the enemy. 

    std::vector<ActionType> GetActionVector() const; //Returns the enemy action pattern.

    ActionType GetCurrentAction() const; //Returns the current enemy action.

    void MoveTowards(Character* targetcharacter); //Pathfinds towards the target character.

    void MoveAwayFrom(Character* targetcharacter); //Pathfinds away from the targer character.

    bool DistanceToCharacterLargerThanThree(Character* targetcharacter) const; //Checks if an enemy can be reached in three steps through tiles that aren't walls.

    bool NextToCharacter(Character* targetcharacter) const; //Checks if the target character is next to the character.

    void TakeAction(Character* targetcharacter); //Proceeds the actionvector index by one and moves the character according to its AI.

    void TakeDamage(int damage); //Damages the character.

    bool MoveToDirection(const char* direction); //Attempts to move the character to the given direction, returns true if successful.

    virtual std::string GetDescription() const = 0; //Overridden by subclasses. Returns the description of the enemy.

    protected:
    EnemyAI enemyai_; //The behavior type of the enemy.
    std::vector<ActionType> actionvector_; //The vector that the enemy will proceed through whenever it takes a turn.
    int indexinactionvector_; //The current index of the action vector.
    std::string name_; //The name of the enemy.
    std::string description_; //A description of the enemy.
};


class Slime : public Enemy {
    public:
    Slime(DungeonTile* tile);
    std::string GetDescription() const;
};

class LargeSlime : public Enemy {
    public:
    LargeSlime(DungeonTile* tile);
    std::string GetDescription() const;
};

class HugeSlime : public Enemy {
    public:
    HugeSlime(DungeonTile* tile);
    std::string GetDescription() const;
};

class SmallSpider : public Enemy {
    public:
    SmallSpider(DungeonTile* tile);
    std::string GetDescription() const;
};

class Spider : public Enemy {
    public:
    Spider(DungeonTile* tile);
    std::string GetDescription() const;
};

class BigSpider : public Enemy {
    public:
    BigSpider(DungeonTile* tile);
    std::string GetDescription() const;
};

class SpitterSpider : public Enemy {
    public:
    SpitterSpider(DungeonTile* tile);
    std::string GetDescription() const;
};

class Skeleton : public Enemy {
    public:
    Skeleton(DungeonTile* tile);
    std::string GetDescription() const;
};

class SkeletonWarrior : public Enemy {
    public:
    SkeletonWarrior(DungeonTile* tile);
    std::string GetDescription() const;
};

class SkeletonKnight : public Enemy {
    public:
    SkeletonKnight(DungeonTile* tile);
    std::string GetDescription() const;
};

class SkeletonArcher : public Enemy {
    public:
    SkeletonArcher(DungeonTile* tile);
    std::string GetDescription() const;
};

class SkeletonMage : public Enemy {
    public:
    SkeletonMage(DungeonTile* tile);
    std::string GetDescription() const;
};

class Lich : public Enemy {
    public:
    Lich(DungeonTile* tile);
    std::string GetDescription() const;
};