


//Restores one health point to the player.
//Using condition: The player has missing health points.
#include "character.hpp"
#include "characterplayer.hpp"
#include "healthpotion.hpp"
//Restores one health point to the player.
//Using condition: The player has missing health points.
HealthPotion::HealthPotion():Potions("Haste Potion"){};
bool  HealthPotion:: CanBeUsed() const {
    return false;
}

void  HealthPotion:: Trigger(){
    //how to reach to player^s health points.
    
};

std::string HealthPotion:: GetDescription() const{
    std::string a= "It is a(n) "+name_+".This potion that allows the player to take two turns instead of one immediately after drinking the potion. It can only be used if there is  at least one enemy in the room. It can only be used once.";
    return a ;
}
