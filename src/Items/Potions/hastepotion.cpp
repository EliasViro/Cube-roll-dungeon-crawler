


//A potion that allows the player to take two turns instead of one
//immediately after drinking the potion.
//Using condition: There are enemies in the same room as the player.

#include "hastepotion.hpp"
HastePotion::HastePotion():Potions("Haste Potion"){};
bool  HastePotion:: CanBeUsed() const {
    return false;
}

void  HastePotion:: Trigger(){
    
};

std::string HastePotion:: GetDescription() const{
    std::string a= "It is a(n) "+name_+".This potion that allows the player to take two turns instead of one immediately after drinking the potion. It can only be used if there is  at least one enemy in the room. It can only be used once.";
    return a ;
}
