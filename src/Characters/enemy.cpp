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
    //mmove direction
    //Attempts to move the character to the given direction,
    //returns -1 if didn't succeed, positive otherwise.
    int target_tileX= targetcharacter->GetXCoordinate();
    int target_tileY = targetcharacter->GetYCoordinate();
    int current_tileX = GetXCoordinate();
    int current_tileY = currenttile_->GetYCoord();
    int ydiff= current_tileY - target_tileY;
    int xdiff= current_tileX - target_tileX;
    // xdiff > 0 => enemy is left, go W
    //xdiff < 0 => enemy is right, go E
    //ydiff > 0 => enemy is up, go N
    //ydiff < 0 => enemy is down , go  S
    int rndm=(rand()%2);
    if(std::abs(xdiff)<std::abs(ydiff)){
        //if it is closer in horizontal direction, go in horizontal direction first
        if (xdiff>0) {
            if(MoveToDirection("W")>0){
                MoveToDirection("W");
                //return true;
            }else{
                if(ydiff>0){
                    if(MoveToDirection("N")<0){
                        //1 is E, 0 is S.
                        if(rndm==1){
                            if(MoveToDirection("E")<0){
                                if(MoveToDirection("S")>0){
                                    MoveToDirection("S");
                                }
                                
                            }else{
                                MoveToDirection("E");
                                //return true;
                            }
                        }else{
                            if(MoveToDirection("S")<0){
                                if(MoveToDirection("E")>0){
                                    MoveToDirection("E");
                                }
                                
                            }else{
                                MoveToDirection("S");
                                //return true;
                            }
                        }
                    }else{
                        MoveToDirection("N");
                        //return true;
                    }
                    
                }else if (ydiff<0){
                    if(MoveToDirection("S")<0){
                        // 1 is E, 0 is N
                        if(rndm==1){
                            if(MoveToDirection("E")<0){
                                if(MoveToDirection("N")>0){
                                    MoveToDirection("N");
                                }
                                
                            }else{
                                MoveToDirection("E");
                                //return true;
                            }
                        }else{
                            if(MoveToDirection("N")<0){
                                if(MoveToDirection("E")>0){
                                    MoveToDirection("E");
                                }
                                
                            }else{
                                MoveToDirection("n");
                                //return true;
                            }
                        }
                    }else{
                        //return true;
                        MoveToDirection("S");
                    }
                }
                
            }
        } else if(xdiff<0) {
            if(MoveToDirection("E")>1){
                MoveToDirection("E");
                //return true;
            }else{
                //return false;
                if (ydiff>0) {
                    if( MoveToDirection("N")<0){
                        //1 is W, 0 is S
                        if(rndm==1){
                            if(MoveToDirection("W")<0){
                                if(MoveToDirection("S")<0){
                                    //return true;
                                    MoveToDirection("S");
                                }
                                
                            }else{
                                //return true;
                                MoveToDirection("W");
                            }
                        }else{
                            if(MoveToDirection("S")<0){
                                if(MoveToDirection("W")<0){
                                    //return true;
                                    MoveToDirection("W");
                                }
                                
                            }else{
                                //return true;
                                MoveToDirection("S");
                            }
                        }
                        
                        
                    }else{
                        //return true;
                        MoveToDirection("N");
                    }
                } else if(ydiff<0) {
                    if(MoveToDirection("S")<0){
                        //1 is W, 0 is N
                        if(rndm==1){
                            if(MoveToDirection("W")<0){
                                if(MoveToDirection("N")<0){
                                    //return true;
                                    MoveToDirection("N");
                                }
                                
                            }else{
                                //return true;
                                MoveToDirection("W");
                            }
                            
                        }else{
                            if(MoveToDirection("N")<0){
                                if(MoveToDirection("W")<0){
                                    //return true;
                                    MoveToDirection("W");
                                }
                                
                            }else{
                                //return true;
                                MoveToDirection("N");
                            }
                        }
                        
                    }else{
                        //return true;
                        MoveToDirection("S");
                    }
                    
                }
            }
            
        }
    } else {
        //if it is closer in vertical direction, start moving vertically
        if (ydiff>0) {
            if( MoveToDirection("N")<0){
                if(xdiff>0){
                    if(MoveToDirection("W")<0){
                        //1 is E, 0 is S
                        if(rndm==1){
                            if(MoveToDirection("E")<0){
                                if(MoveToDirection("S")>0){
                                    MoveToDirection("S");
                                    //return true;
                                }
                            }else{
                                MoveToDirection("E");
                            }
                            
                            
                        }else{
                            if(MoveToDirection("S")<0){
                                if(MoveToDirection("E")>0){
                                    MoveToDirection("E");
                                    //return true;
                                }
                            }else{
                                MoveToDirection("S");
                            }
                        }
                        
                        
                    }else{
                        //return true;
                        MoveToDirection("W");
                    }
                    
                    
                }else if(xdiff<0){
                    if(MoveToDirection("E")<0){
                        if(rndm==1){
                            if(MoveToDirection("W")<0){
                                if(MoveToDirection("S")>0){
                                    MoveToDirection("S");
                                    //return true;
                                }else{
                                    //problem
                                
                                }
                            }else{
                                MoveToDirection("W");
                                //return true;
                            }
                            
                        }else{
                            if(MoveToDirection("S")<0){
                                if(MoveToDirection("W")>0){
                                    MoveToDirection("W");
                                    //return true;
                                }else{
                                    //problem
                                
                                }
                            }else{
                                MoveToDirection("S");
                                //return true;
                            }
                        }
                        
                        
                    }else{
                        //return true;
                        MoveToDirection("E");
                    }
                    
                }
                
            }else{
                MoveToDirection("N");
            }
            
        } else if(ydiff<0) {
            if(MoveToDirection("S")<0){
                if (xdiff>0) {
                    MoveToDirection("W");
                } else if(xdiff<0) {
                    if(MoveToDirection("E")<0){
                        //1 is W, 0 is N
                        if(rndm==1){
                            if(MoveToDirection("W")<0){
                                if(MoveToDirection("N")>0){
                                    MoveToDirection("N");
                                    //return true;
                                }
                                
                            }else{
                                MoveToDirection("W");
                            }
                            
                        }else{
                            if(MoveToDirection("N")<0){
                                if(MoveToDirection("W")>0){
                                    MoveToDirection("W");
                                    //return true;
                                }
                                
                            }else{
                                MoveToDirection("N");
                            }
                            
                        }
                        
                    }else{
                        MoveToDirection("E");
                        //return true;
                    }
                }
                
            }else{
                MoveToDirection("S");
            }
        }
        
    }
    
}

void Enemy::MoveAwayFrom(Character* targetcharacter) {
    
    int target_tileX= targetcharacter->GetXCoordinate();
    int target_tileY = targetcharacter->GetYCoordinate();
    int current_tileX = GetXCoordinate();
    int current_tileY = currenttile_->GetYCoord();
    int ydiff= current_tileY - target_tileY;
    int xdiff= current_tileX - target_tileX;
    // xdiff > 0 => enemy is down, go E
    //xdiff < 0 => enemy is up, go W
    //ydiff > 0 => enemy is right, go S
    //ydiff < 0 => enemy is left , go  N
    //first go horizontal
    int rndm=(rand()%2);
    if(std::abs(xdiff)<std::abs(ydiff)){
        //if it is closer in horizontal direction, go in horizontal direction first
        if (xdiff>0) {
            if(MoveToDirection("E")>0){
                MoveToDirection("E");
                //return true;
            }else{
                if(ydiff>0){
                    if(MoveToDirection("S")<0){
                        //1 is E, 0 is S.
                        if(rndm==1){
                            if(MoveToDirection("W")<0){
                                if(MoveToDirection("N")>0){
                                    MoveToDirection("N");
                                }
                                
                            }else{
                                MoveToDirection("W");
                                //return true;
                            }
                        }else{
                            if(MoveToDirection("N")<0){
                                if(MoveToDirection("W")>0){
                                    MoveToDirection("W");
                                }
                                
                            }else{
                                MoveToDirection("N");
                                //return true;
                            }
                        }
                    }else{
                        MoveToDirection("S");
                        //return true;
                    }
                    
                }else if (ydiff<0){
                    if(MoveToDirection("N")<0){
                        // 1 is E, 0 is N
                        if(rndm==1){
                            if(MoveToDirection("W")<0){
                                if(MoveToDirection("S")>0){
                                    MoveToDirection("S");
                                }
                                
                            }else{
                                MoveToDirection("W");
                                //return true;
                            }
                        }else{
                            if(MoveToDirection("S")<0){
                                if(MoveToDirection("W")>0){
                                    MoveToDirection("W");
                                }
                                
                            }else{
                                MoveToDirection("S");
                                //return true;
                            }
                        }
                    }else{
                        //return true;
                        MoveToDirection("N");
                    }
                }
                
            }
        } else if(xdiff<0) {
            if(MoveToDirection("W")>1){
                MoveToDirection("W");
                //return true;
            }else{
                //return false;
                if (ydiff>0) {
                    if( MoveToDirection("S")<0){
                        //1 is W, 0 is S
                        if(rndm==1){
                            if(MoveToDirection("E")<0){
                                if(MoveToDirection("N")<0){
                                    //return true;
                                    MoveToDirection("N");
                                }
                                
                            }else{
                                //return true;
                                MoveToDirection("E");
                            }
                        }else{
                            if(MoveToDirection("N")<0){
                                if(MoveToDirection("E")<0){
                                    //return true;
                                    MoveToDirection("E");
                                }
                                
                            }else{
                                //return true;
                                MoveToDirection("N");
                            }
                        }
                        
                        
                    }else{
                        //return true;
                        MoveToDirection("S");
                    }
                } else if(ydiff<0) {
                    if(MoveToDirection("N")<0){
                        //1 is W, 0 is N
                        if(rndm==1){
                            if(MoveToDirection("E")<0){
                                if(MoveToDirection("S")<0){
                                    //return true;
                                    MoveToDirection("S");
                                }
                                
                            }else{
                                //return true;
                                MoveToDirection("E");
                            }
                            
                        }else{
                            if(MoveToDirection("S")<0){
                                if(MoveToDirection("E")<0){
                                    //return true;
                                    MoveToDirection("E");
                                }
                                
                            }else{
                                //return true;
                                MoveToDirection("S");
                            }
                        }
                        
                    }else{
                        //return true;
                        MoveToDirection("N");
                    }
                    
                }
            }
            
        }
    } else {
        //if it is closer in vertical direction, start moving vertically
        if (ydiff>0) {
            if( MoveToDirection("S")<0){
                if(xdiff>0){
                    if(MoveToDirection("E")<0){
                        //1 is E, 0 is S
                        if(rndm==1){
                            if(MoveToDirection("W")<0){
                                if(MoveToDirection("N")>0){
                                    MoveToDirection("N");
                                    //return true;
                                }
                            }else{
                                MoveToDirection("W");
                            }
                            
                            
                        }else{
                            if(MoveToDirection("N")<0){
                                if(MoveToDirection("W")>0){
                                    MoveToDirection("W");
                                    //return true;
                                }
                            }else{
                                MoveToDirection("N");
                            }
                        }
                        
                        
                    }else{
                        //return true;
                        MoveToDirection("E");
                    }
                    
                    
                }else if(xdiff<0){
                    if(MoveToDirection("W")<0){
                        if(rndm==1){
                            if(MoveToDirection("E")<0){
                                if(MoveToDirection("N")>0){
                                    MoveToDirection("N");
                                    //return true;
                                }
                            }else{
                                MoveToDirection("E");
                                //return true;
                            }
                            
                        }else{
                            if(MoveToDirection("N")<0){
                                if(MoveToDirection("E")>0){
                                    MoveToDirection("E");
                                    //return true;
                                }
                            }else{
                                MoveToDirection("N");
                                //return true;
                            }
                        }
                        
                        
                    }else{
                        //return true;
                        MoveToDirection("W");
                    }
                    
                }
                
            }else{
                MoveToDirection("S");
            }
            
        } else if(ydiff<0) {
            if(MoveToDirection("N")<0){
                if (xdiff>0) {
                    MoveToDirection("E");
                } else if(xdiff<0) {
                    if(MoveToDirection("W")<0){
                        //1 is W, 0 is N
                        if(rndm==1){
                            if(MoveToDirection("E")<0){
                                if(MoveToDirection("S")>0){
                                    MoveToDirection("S");
                                    //return true;
                                }
                                
                            }else{
                                MoveToDirection("E");
                            }
                            
                        }else{
                            if(MoveToDirection("S")<0){
                                if(MoveToDirection("E")>0){
                                    MoveToDirection("E");
                                    //return true;
                                }
                                
                            }else{
                                MoveToDirection("S");
                            }
                            
                        }
                        
                    }else{
                        MoveToDirection("W");
                        //return true;
                    }
                }
                
            }else{
                MoveToDirection("N");
            }
        }
        
    }
    
}

bool Enemy::DistanceToCharacterLargerThanThree(Character* targetcharacter) const {
    DungeonTile* measurertile = targetcharacter->GetCurrentTile();
    int distance = 0;
    std::string xdir = "";
    std::string ydir = "";
    int ydifference = GetYCoordinate() - measurertile->GetYCoord();
    int xdifference = GetXCoordinate() - measurertile->GetXCoord();
    while ((measurertile->GetXCoord() != GetXCoordinate() && measurertile->GetYCoord() != GetYCoordinate()) || distance < 3) {
        if (xdifference > 0) {
            xdir = "E";
        }
        else {
            xdir = "W";
        }
        if (ydifference > 0) {
            ydir = "S";
        }
        else {
            ydir = "N";
        }
        if (abs(xdifference) > abs(ydifference)) {
            if (measurertile->GetTileNeighbor(xdir.c_str())->GetTileType() != Wall) {
                measurertile = measurertile->GetTileNeighbor(xdir.c_str());
            }
            else {
                measurertile = measurertile->GetTileNeighbor(ydir.c_str());
            }
        }
        else if (abs(ydifference) > abs(xdifference)) {
            if (measurertile->GetTileNeighbor(ydir.c_str())->GetTileType() != Wall) {
                measurertile = measurertile->GetTileNeighbor(ydir.c_str());
            }
            else {
                measurertile = measurertile->GetTileNeighbor(xdir.c_str());
            }
        }
        else {
            int randomnumber = rand() % 2 + 1;
            if (randomnumber == 1) {
                if (measurertile->GetTileNeighbor(ydir.c_str())->GetTileType() != Wall) {
                    measurertile = measurertile->GetTileNeighbor(ydir.c_str());
                }
                else {
                    measurertile = measurertile->GetTileNeighbor(xdir.c_str());
                }
            }
            else {
                if (measurertile->GetTileNeighbor(xdir.c_str())->GetTileType() != Wall) {
                    measurertile = measurertile->GetTileNeighbor(xdir.c_str());
                }
                else {
                    measurertile = measurertile->GetTileNeighbor(ydir.c_str());
                }
            }
        }
        ydifference = GetYCoordinate() - measurertile->GetYCoord();
        xdifference = GetXCoordinate() - measurertile->GetXCoord();
        distance++;
    }

    if (measurertile->GetXCoord() == GetXCoordinate() && measurertile->GetYCoord() == GetYCoordinate()) {
        return false;
    }
    else {
        return true;
    }
}

bool Enemy::NextToCharacter(Character* targetcharacter) const {
    return ((GetXCoordinate() == targetcharacter->GetXCoordinate() && (abs(GetYCoordinate() - targetcharacter->GetYCoordinate()) == 1)) || (GetYCoordinate() == targetcharacter->GetYCoordinate() && (abs(GetXCoordinate() - targetcharacter->GetXCoordinate()))));
}

void Enemy::TakeAction(Character* targetcharacter, int fillernumber) {
    srand(time(NULL));
    fillernumber = 1;
    RemoveDefensePoints();
    if (isstunned_ == 0) {
        if (enemyai_ == Random) {
            int randomnumber = rand() % 4 + 1;
            int movedsuccessfully = -1;
            bool attemptednorth = false;
            bool attemptedeast = false;
            bool attemptedwest = false;
            bool attemptedsouth = false;
            while (movedsuccessfully < 0 && !(attemptednorth && attemptedwest && attemptedeast && attemptedsouth)) {
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
                if (randomnumber == 4 && !attemptedsouth) {
                    movedsuccessfully = MoveToDirection("S");
                    attemptedsouth = true;
                }
                randomnumber = rand() % 4 + 1;
            }
        }
        if (enemyai_ == Aggressive) {
            MoveTowards(targetcharacter);
        }
        if (enemyai_ == Careful) {
            if (DistanceToCharacterLargerThanThree(targetcharacter)) {
                MoveTowards(targetcharacter);
            }
            else {
                MoveAwayFrom(targetcharacter);
            }
        }
        if (currenttile_->GetTrapState() == Spikes) {
            TakeDamage(1);
        }
        if (indexinactionvector_ < actionvector_.size() - 1) {
            indexinactionvector_+= fillernumber;
        }
        else {
            indexinactionvector_ = 0;
        }
        if (actionvector_[indexinactionvector_] == Defend_1) {
            AddDefensePoints(1);
        }
        if (actionvector_[indexinactionvector_] == Defend_2) {
            AddDefensePoints(2);
        }
        if (actionvector_[indexinactionvector_] == Defend_3) {
            AddDefensePoints(3);
        }
        if (actionvector_[indexinactionvector_] == Melee_1 && NextToCharacter(targetcharacter)) {
            targetcharacter->TakeDamage(1);
            if (targetcharacter->GetDefensePoints() > 0) {
                Stun(1);
            }
        }
        if (actionvector_[indexinactionvector_] == Melee_2 && NextToCharacter(targetcharacter)) {
            targetcharacter->TakeDamage(2);
            if (targetcharacter->GetDefensePoints() > 0) {
                Stun(1);
            }
        }
        if (actionvector_[indexinactionvector_] == Melee_3 && NextToCharacter(targetcharacter)) {
            targetcharacter->TakeDamage(3);
            if (targetcharacter->GetDefensePoints() > 0) {
                Stun(1);
            }
        }
        if (actionvector_[indexinactionvector_] == Ranged_1 && !DistanceToCharacterLargerThanThree(targetcharacter)) {
            targetcharacter->TakeDamage(1);
        }
        if (actionvector_[indexinactionvector_] == Ranged_2 && !DistanceToCharacterLargerThanThree(targetcharacter)) {
            targetcharacter->TakeDamage(2);
        }
        if (actionvector_[indexinactionvector_] == Ranged_3 && !DistanceToCharacterLargerThanThree(targetcharacter)) {
            targetcharacter->TakeDamage(3);
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
    }
}

int Enemy::MoveToDirection(const char* direction) {
    if (currenttile_->GetTileNeighbor(direction)->IsPassable()) {
        currenttile_->GetTileNeighbor(direction)->SetCharacter();
        currenttile_->RemoveCharacter();
        currenttile_ = currenttile_->GetTileNeighbor(direction);
        return 1;
    }
    else {
        return -1;
    }
}

std::string Enemy::GetDescription() const {
    return description_;
}


Slime::Slime(DungeonTile* tile) : Enemy("Slime", "A blindly wandering blob of acidic jelly that tries to eat anything near it.", tile, Random, {Melee_1, Empty}) {}

LargeSlime::LargeSlime(DungeonTile* tile) : Enemy("Large slime", "A blindly wandering large blob of acidic jelly that tries to eat anything near it.", tile, Random, {Melee_2, Empty}) {}

HugeSlime::HugeSlime(DungeonTile* tile) : Enemy("Huge slime", "A blindly wandering enormous blob of acidic jelly that tries to eat anything near it.", tile, Random, {Melee_3, Empty}) {}

SmallSpider::SmallSpider(DungeonTile* tile) : Enemy("Spider", "A cave-dwelling arachnid with a set of sharp fangs.", tile, Aggressive, {Melee_1, Empty}) {}

Spider::Spider(DungeonTile* tile) : Enemy("Large spider", "An unusually large cave-dwelling arachnid with a set of long sharp fangs.", tile, Aggressive, {Melee_1, Melee_1, Empty}) {}

BigSpider::BigSpider(DungeonTile* tile) : Enemy("Huge spider", "A massive cave-dwelling arachnid with a set of enormous sharp fangs.", tile, Aggressive, {Melee_2, Melee_2, Empty}) {}

SpitterSpider::SpitterSpider(DungeonTile* tile) : Enemy("Spitter spider", "A large cave-dwelling arachnid that prefers to spit acidic venom from a distance.", tile, Careful, {Ranged_1, Empty, Melee_1, Empty}) {}

Skeleton::Skeleton(DungeonTile* tile) : Enemy("Skeleton", "The rotting skeleton of some poor peasant reanimated by dark magic. It is wielding a sword and a small shield.", tile, Aggressive, {Melee_1, Defend_1}) {}

SkeletonWarrior::SkeletonWarrior(DungeonTile* tile) : Enemy("Skeleton warrior", "The rotting skeleton of some poor warrior reanimated by dark magic. It is wielding a warhammer and a shield.", tile, Aggressive, {Melee_2, Defend_2}) {}

SkeletonKnight::SkeletonKnight(DungeonTile* tile) : Enemy("Skeleton knight", "The rotting skeleton of some poor knight reanimated by dark magic. It is wearing a full suit of armor and wields a sword.", tile, Aggressive, {Melee_1, Defend_3, Defend_3}) {}

SkeletonArcher::SkeletonArcher(DungeonTile* tile) : Enemy("Skeleton archer", "The rotting skeleton of some poor adventurer reanimated by dark magic. It is wielding a bow and has a quiver full of arrows.", tile, Careful, {Ranged_2, Empty, Empty, Empty}) {}

SkeletonMage::SkeletonMage(DungeonTile* tile) : Enemy("Skeleton mage", "The rotting skeleton of some poor mage reanimated by dark magic. It is wielding a magic staff that glows menacingly in the darkness.", tile, Careful, {Ranged_1, Empty, Defend_1}) {}

Lich::Lich(DungeonTile* tile) : Enemy("The Lich", "The undead king of the underworld, said to have been the most powerful necromancer who ever existed when he was still alive.", tile, Stationary, {Ranged_2, Defend_3, Melee_2}) {}
