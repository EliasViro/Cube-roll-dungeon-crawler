


//A basic melee weapon.
//Range - 1, damage - 1, max cooldown - 4, durability - 999
#include "meleeweapon.hpp"
#include "shortsword.hpp"
Shortsword::Shortsword():Meleeweapon("Short Sword", 999, 4, 1){
    isactive_=false;
    cooldown_=0;
}
