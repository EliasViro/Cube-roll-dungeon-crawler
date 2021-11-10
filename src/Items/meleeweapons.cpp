#include "meleeweapons.hpp"


//A class that all melee weapons inherit.
//The conditions for using a melee weapon:
//-An enemy is in range of the weapon
//-The weapon isn't on cooldown.


bool Meleeweapon::CanBeUsed() const{
    
    if((cooldown_==0 && isactive_)){
        return true;
    }
     
    return false;
     
}

void Meleeweapon::Trigger(){};

std::string& Meleeweapon::GetDescription() const {
    std::string a= "It is a(n) "+name_+". It has a ranger of 1. It's maximum cooldown is "+std::to_string(maxcooldown_)+". It damages "+ std::to_string(damage_)+ " points. It's  current durability is "+ std::to_string(durability_)+". It's current cooldown is "+std::to_string(cooldown_)+".";
    return a ;
   
}



//A melee weapon.
//Range - 1, damage - 2, max cooldown - 6, durability - 999

Axe::Axe():Meleeweapon("Axe",999, 6,2){
    cooldown_=0;
    isactive_=false;
    
};



//A basic melee weapon with improved attack speed.
//Range - 1, damage - 1, max cooldown - 3, durability - 999

Dagger::Dagger ():Meleeweapon("Dagger", 999,3, 1){
    cooldown_=0;
    isactive_=false;
};



//A powerful melee weapon that hits all enemies in the attack range.
//Range - 1, damage - 2, max cooldown - 6, durability - 999

GreatSword::GreatSword () : Meleeweapon("Greatsword", 999,6, 2) {
    cooldown_=0;
    isactive_=false;
};




//A melee weapon.
//Range - 1, damage - 2, max cooldown - 5, durability - 999

LongSword::LongSword():Meleeweapon("Longsword", 999, 5, 2){
    cooldown_=0;
    isactive_=false;
}



//A basic melee weapon.
//Range - 1, damage - 1, max cooldown - 4, durability - 999

Shortsword::Shortsword():Meleeweapon("Shortsword", 999, 4, 1){
    isactive_=false;
    cooldown_=0;
}
