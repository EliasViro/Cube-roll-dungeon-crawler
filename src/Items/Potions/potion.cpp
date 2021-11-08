


//A class that all potions inherit.
//Potions have only one point of durability.
#include "potion.hpp"
Potions::Potions(const std::string& name ):Item(name,Potion, 1,0){
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
