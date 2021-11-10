#include "item.hpp"


//A class that all ranged weapons inherit.
//The maximum range of any ranged weapon is 3.
//The conditions for using a ranged weapon:
//-An enemy is in range of the weapon, but not in a tile next to the 
//player and the attack of the ranged weapon can "walk" to the same tile
//as the enemy without passing walls in moves specified by the weapon's 
//range.
//-The weapon isn't on cooldown.