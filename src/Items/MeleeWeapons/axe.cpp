


//A melee weapon.
//Range - 1, damage - 2, max cooldown - 6, durability - 999
#include "meleeweapon.hpp"
#include "axe.hpp"
Axe::Axe():Meleeweapon("Axe",999, 6,2){
    cooldown_=0;
    isactive_=false;
    
};
