#include "potions.hpp"


//A class that all potions inherit.
//Potions have only one point of durability.

Potion::Potion(const std::string& name ) : Item(name,PotionItem, 1,0){
    used_=false;
    name_=name;
};

/*
bool Potions::CanBeUsed() const{
    return true;
}


void Potions:: Trigger(){};

std::string Potions::GetDescription() const{
    std::string a= "It is a(n) "+name_+".It is a type of a potion.". It damages "+ std::to_string(damage_)+ " points. It's  current durability is "+ std::to_string(durability_)+". It's current cooldown is "+std::to_string(cooldown_)+".";
    return a ;
    
};
 */




//A potion that allows the player to take two turns instead of one
//immediately after drinking the potion.
//Using condition: There are enemies in the same room as the player.

HastePotion::HastePotion() : Potion("Haste Potion") {};

bool  HastePotion:: CanBeUsed() const {
    return false;
}

void  HastePotion:: Trigger() {
    
};

std::string& HastePotion::GetDescription() const {
    std::string a= "It is a(n) "+name_+".This potion that allows the player to take two turns instead of one immediately after drinking the potion. It can only be used if there is  at least one enemy in the room. It can only be used once.";
    return a ;
}



//Restores one health point to the player.
//Using condition: The player has missing health points.

//Restores one health point to the player.
//Using condition: The player has missing health points.
HealthPotion::HealthPotion() : Potion("Haste Potion") {};
bool  HealthPotion:: CanBeUsed() const {
    return false;
}

void  HealthPotion:: Trigger(){
    //how to reach to player^s health points.
    
};

std::string& HealthPotion::GetDescription() const{
    std::string a= "It is a(n) "+name_+".This potion that allows the player to take two turns instead of one immediately after drinking the potion. It can only be used if there is  at least one enemy in the room. It can only be used once.";
    return a ;
}
