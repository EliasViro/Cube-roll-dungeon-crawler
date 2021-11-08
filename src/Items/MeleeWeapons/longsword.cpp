


//A melee weapon.
//Range - 1, damage - 2, max cooldown - 5, durability - 999

#include "longsword.hpp"
LongSword::LongSword():Meleeweapon("Long Sword", 999, 5, 2){
    cooldown_=0;
    isactive_=false;
}
