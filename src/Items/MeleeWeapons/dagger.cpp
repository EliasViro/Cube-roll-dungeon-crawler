


//A basic melee weapon with improved attack speed.
//Range - 1, damage - 1, max cooldown - 3, durability - 999
#include "dagger.hpp"
Dagger::Dagger ():Meleeweapon("Dagger", 999,3, 1){
    cooldown_=0;
    isactive_=false;
};
