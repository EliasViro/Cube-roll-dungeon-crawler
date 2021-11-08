


//A powerful melee weapon that hits all enemies in the attack range.
//Range - 1, damage - 2, max cooldown - 6, durability - 999

#include "greatsword.hpp"
GreatSword::GreatSword ():Meleeweapon("Great Sword", 999,6, 2){
    cooldown_=0;
    isactive_=false;
};
