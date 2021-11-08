


//A class that all melee weapons inherit.
//The conditions for using a melee weapon:
//-An enemy is in range of the weapon
//-The weapon isn't on cooldown.
#include "meleeweapon.hpp"





bool Meleeweapon::CanBeUsed() const{
    
    if((cooldown_==0 && isactive_)){
        return true;
    }
     
    return false;
     
}

void Meleeweapon::Trigger(){};

std::string Meleeweapon::GetDescription() const {
    std::string a= "It is a(n) "+name_+". It has a ranger of 1. It's maximum cooldown is "+std::to_string(maxcooldown_)+". It damages "+ std::to_string(damage_)+ " points. It's  current durability is "+ std::to_string(durability_)+". It's current cooldown is "+std::to_string(cooldown_)+".";
    return a ;
    
   
}
