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
    int target_tileX = targetcharacter->GetXCoordinate();
    int target_tileY = targetcharacter->GetYCoordinate();
    int current_tileX = GetXCoordinate();
    int current_tileY = GetYCoordinate();
    int ydiff = current_tileY - target_tileY;
    int xdiff = current_tileX - target_tileX;
    // xdiff > 0 => enemy is left, go W
    //xdiff < 0 => enemy is right, go E
    //ydiff > 0 => enemy is up, go N
    //ydiff < 0 => enemy is down , go  S
    int rndm = (rand() % 2);
    if (std::abs(xdiff) < std::abs(ydiff)) {
        //if it is closer in horizontal direction, go in horizontal direction first
        if (xdiff > 0) {
            dirkeep = MoveToDirection("W"); //-1 ==> couldn't move, 1==> moved
            if (dirkeep == -1 ){
                if(ydiff>0){
                    dirkeep=MoveToDirection("N");
                    if (dirkeep == -1) {
                        if ( rndm == 1 ){
                            if(currenttile_->GetTileNeighbor("E")->IsPassable()){
                                //it can move in E direction.
                                //but checks if the neighbours neighbour is a pit or a wall.
                                if((currenttile_->GetTileNeighbor("E")->GetTileNeighbor("N")->GetTileType() !=Wall)&&(currenttile_->GetTileNeighbor("E")->GetTileNeighbor("N")->GetTileType() !=Pit)){
                                    MoveToDirection("E");
                                }
                                else if(currenttile_->GetTileNeighbor("W")->IsPassable() ){
                                    //it can move in W direction
                                    MoveToDirection("W");
                                    
                                }
                                else{
                                    MoveToDirection("E");
                                }
                            }
                            else {
                                MoveToDirection("S");
                            }
                        }
                        else{
                            if(currenttile_->GetTileNeighbor("W")->IsPassable()){
                                //it can move in E direction.
                                //but checks if the neighbours neighbour is a pit or a wall.
                                if((currenttile_->GetTileNeighbor("W")->GetTileNeighbor("N")->GetTileType() !=Wall)&&(currenttile_->GetTileNeighbor("W")->GetTileNeighbor("N")->GetTileType() !=Pit)){
                                    MoveToDirection("W");
                                }
                                else if(currenttile_->GetTileNeighbor("E")->IsPassable() ){
                                    //it can move in W direction
                                    MoveToDirection("E");
                                    
                                }
                                else{
                                    MoveToDirection("W");
                                }
                            }
                            else {
                                MoveToDirection("S");
                            }
                            
                        }
                    }
                        
                        
                        if (rndm == 1) {
                            if (MoveToDirection("E") < 0) {
                                if (MoveToDirection("S") > 0) {
                                    MoveToDirection("S");
                                }
                                
                            }
                            else {
                                MoveToDirection("E");
                                //return true;
                            }
                        }
                        else {
                            if (MoveToDirection("S") < 0){
                                if (MoveToDirection("E") > 0){
                                    MoveToDirection("E");
                                }
                                
                            }
                            else {
                                MoveToDirection("S");
                                //return true;
                            }
                        }
                        
                    }
                }
            }
            else{
                
            }
            if (MoveToDirection("W") > 0) {
                MoveToDirection("W");
                //return true;
            } 
            else {
                if (ydiff > 0) {
                    if (MoveToDirection("N") < 0) {
                        //1 is E, 0 is S.
                        if (rndm == 1) {
                            if (MoveToDirection("E") < 0) {
                                if (MoveToDirection("S") > 0) {
                                    MoveToDirection("S");
                                }
                                
                            }
                            else {
                                MoveToDirection("E");
                                //return true;
                            }
                        }
                        else {
                            if (MoveToDirection("S") < 0){
                                if (MoveToDirection("E") > 0){
                                    MoveToDirection("E");
                                }
                                
                            } 
                            else {
                                MoveToDirection("S");
                                //return true;
                            }
                        }
                    }
                    else {
                        MoveToDirection("N");
                        //return true;
                    }
                    
                }
                else if (ydiff < 0) {
                    if(MoveToDirection("S")<0){
                        // 1 is E, 0 is N
                        if (rndm == 1) {
                            if ( MoveToDirection("E") < 0){
                                if (MoveToDirection("N") > 0){
                                    MoveToDirection("N");
                                }
                                
                            }else{
                                MoveToDirection("E");
                                //return true;
                            }
                        }
                        else {
                            if(MoveToDirection("N") < 0){
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





/*
Moving towards:

1. Save X and Y differences to the target (diff = ownpos - targetpos)
2. See which one is larger with abs(diff). If X is larger -> horizontal movement, if Y is larger -> vertical movement. 
If both are the same, skip to step 7 (this would be just the last else path).
3. Check if the difference is positive or negative. Positive means E for horizontal, S for verical. Negative means W for horizontal, N for vertical.
4. Use MoveToDirection(dir) and save the return value. Check if the return value was negative, and if it was, check if the difference value of
the attempted axis is zero. In case it was, randomize either of the neighboring tiles and ask its neighbor in the movement direction if it is a Wall or a Pit.
(tile->GetTileType() != Wall && tile ->GetTileType() != Pit). If the neighbor of the neighbor isn't a wall or a pit, move onto the tile whose neighbor was checked.
Otherwise attempt to move to the direction that wasn't randomly picked **without** checking its neighbor (remember the return value!). If this fails, resume from step 6.
take the character closer to the target (so if attempted horizontal first, attempt vertical, if attempted vertical first, attempt horizontal)
5. If the return value from that is negative as well, attempt the direction that leads the least away from the target (so the one with smaller difference)
6. If that fails as well, attempt the last available direction, no return value checking is needed.

7. In case both difference absolute values are equal (the character is diagonally located to the item), 
select either horizontal or vertical randomly and check if the tile is passable. 
If it is, check if **either** of its neighbors **towards** the player isn't a wall or a pit tile (tile->GetTileType() != Wall && tile ->GetTileType() != Pit)
If this check succeeds, move to that direction. Otherwise pick the other direction (if horizontal was attempted first, try vertical, if vertical was
attempted first, try horizontal) and just move there.
*/
