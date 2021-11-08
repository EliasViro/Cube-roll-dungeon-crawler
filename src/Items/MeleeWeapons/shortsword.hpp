


//A basic melee weapon.
//Range - 1, damage - 1, max cooldown - 4, durability - 999
#include "items.hpp"
#include "meleeweapon.hpp"
#ifndef shortsword_hpp
#define shortsword_hpp

#include <stdio.h>
class Shortsword: public Meleeweapon{
public:
    Shortsword();
};

#endif /* shortsword_hpp */
