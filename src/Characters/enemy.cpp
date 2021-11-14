#include "enemy.hpp"
#include <cmath>

//Enemy is a class that all enemy type classes inherit. Holds information
//about the movement speed and attack damage of 
//an enemy character, its own location in a room and a vector that holds
//its action pattern that the enemy will proceed through by one every time
//it takes a turn. Enemies will randomize the step they are on in their
//action pattern when they are created.


Enemy::Enemy(const std::string& name, const std::string& description, DungeonTile* tile, EnemyAI enemyai, std::vector<ActionType> actionvector)
    : Character(EnemyCharacter, 1, tile), enemyai_(enemyai), actionvector_(actionvector), name_(name), description_(description) {}

EnemyAI Enemy::GetEnemyAI() const {
    return enemyai_;
}

std::vector<ActionType> Enemy::GetActionVector() const {
    return actionvector_;
}

ActionType Enemy::GetCurrentAction() const {
    return actionvector_[indexinactionvector_];
}

void Enemy::MoveTowards(Character* targetcharacter) {
    //PATHFINDING TOWARDS THE TARGET. AVOID INPASSABLE TILES.
}

void Enemy::MoveAwayFrom(Character* targetcharacter) {
    //PATHFINDING AWAY FROM THE TARGET. AVOID INPASSABLE TILES.
}

int Enemy::DistanceToCharacter(Character* targetcharacter) const {
    std::pair<int, int> measurer = std::make_pair(GetXCoordinate(), GetYCoordinate());
    int distance = 0;
    int ydifference = abs(GetYCoordinate() - targetcharacter->GetYCoordinate());
    int xdifference = abs(GetYCoordinate() - targetcharacter->GetYCoordinate());
    while (measurer.first != targetcharacter->GetXCoordinate() && measurer.second != targetcharacter->GetYCoordinate()) {
        if (xdifference > ydifference) {
            //Implemententation still underway
        }
        else if (ydifference > xdifference) {

        }
        else {

        }
        xdifference = abs(measurer.first - targetcharacter->GetYCoordinate());
        ydifference = abs(measurer.second - targetcharacter->GetXCoordinate());
    }
    return distance;
}

void Enemy::TakeAction(Character* targetcharacter) {
    srand(time(NULL));
    RemoveDefensePoints();
    if (!isstunned_) {
        if (enemyai_ == Random) {
            int randomnumber = rand() % 4 + 1;
            bool movedsuccessfully = false;
            bool attemptednorth = false;
            bool attemptedeast = false;
            bool attemptedwest = false;
            bool attemptedsouth = false;
            while (!movedsuccessfully || !(attemptednorth && attemptedwest && attemptedeast && attemptedsouth)) {
                if (randomnumber == 1 && !attemptednorth) {
                    movedsuccessfully = MoveToDirection("N");
                    attemptednorth = true;
                }
                if (randomnumber == 2 && !attemptedeast) {
                    movedsuccessfully = MoveToDirection("E");
                    attemptedeast = true;
                }
                if (randomnumber == 3 && !attemptedwest) {
                    movedsuccessfully = MoveToDirection("W");
                    attemptedwest = true;
                }
                if (randomnumber == 4 && attemptedsouth) {
                    movedsuccessfully = MoveToDirection("S");
                    attemptedsouth = true;
                }
            }
        }
        if (enemyai_ == Aggressive) {
            MoveTowards(targetcharacter);
        }
        if (enemyai_ == Careful) {
            if (DistanceToCharacter(targetcharacter) >= 3) {
                MoveTowards(targetcharacter);
            }
            else {
                MoveAwayFrom(targetcharacter);
            }
        }
        if (indexinactionvector_ < actionvector_.size() - 1) {
        indexinactionvector_++;
        }
        else {
            indexinactionvector_ = 0;
        }
        if (actionvector_[indexinactionvector_] = Defend_1) {
            AddDefensePoints(1);
        }
        if (actionvector_[indexinactionvector_] = Defend_2) {
            AddDefensePoints(2);
        }
        if (actionvector_[indexinactionvector_] = Defend_3) {
            AddDefensePoints(3);
        }
        if (actionvector_[indexinactionvector_] == Melee_1 && DistanceToCharacter(targetcharacter) == 1) {
            targetcharacter->TakeDamage(1);
            if (targetcharacter->GetDefensePoints() > 0) {
                Stun();
            }
        }
        if (actionvector_[indexinactionvector_] == Melee_2 && DistanceToCharacter(targetcharacter) == 1) {
            targetcharacter->TakeDamage(2);
            if (targetcharacter->GetDefensePoints() > 0) {
                Stun();
            }
        }
        if (actionvector_[indexinactionvector_] == Melee_3 && DistanceToCharacter(targetcharacter) == 1) {
            targetcharacter->TakeDamage(3);
            if (targetcharacter->GetDefensePoints() > 0) {
                Stun();
            }
        }
        if (actionvector_[indexinactionvector_] == Ranged_1 && DistanceToCharacter(targetcharacter) <= 3) {
            targetcharacter->TakeDamage(1);
        }
        if (actionvector_[indexinactionvector_] == Ranged_2 && DistanceToCharacter(targetcharacter) <= 3) {
            targetcharacter->TakeDamage(1);
        }
        if (actionvector_[indexinactionvector_] == Ranged_3 && DistanceToCharacter(targetcharacter) <= 3) {
            targetcharacter->TakeDamage(1);
        }
    }
    else {
        UnStun();
    }
}

void Enemy::TakeDamage(int damage) {
    healthpoints_ = healthpoints_ - (damage - defensepoints_);
    if (healthpoints_ <= 0) {
        currenttile_->RemoveCharacter();
        delete(this);
    }
}


Slime::Slime(DungeonTile* tile) : Enemy("Slime", "A blindly wandering blob of acidic jelly that tries to eat anything near it.", tile, Random, {Melee_1, Empty}) {}
std:: string Slime::GetDescription() const { return description_; }

LargeSlime::LargeSlime(DungeonTile* tile) : Enemy("Large slime", "A blindly wandering large blob of acidic jelly that tries to eat anything near it.", tile, Random, {Melee_2, Empty}) {}
std:: string LargeSlime::GetDescription() const { return description_; }

HugeSlime::HugeSlime(DungeonTile* tile) : Enemy("Huge slime", "A blindly wandering enormous blob of acidic jelly that tries to eat anything near it.", tile, Random, {Melee_3, Empty}) {}
std:: string HugeSlime::GetDescription() const { return description_; }

Rat::Rat(DungeonTile* tile) : Enemy("Giant rat", "A terrifyingly oversized rat. Its eyes have a ravenous glaze.", tile, Aggressive, {Melee_1, Empty}) {}
std:: string Rat::GetDescription() const { return description_; }