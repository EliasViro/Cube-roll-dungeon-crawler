


//A class that all melee weapons inherit.
//The conditions for using a melee weapon:
//-An enemy is in range of the weapon
//-The weapon isn't on cooldown.
#include <stdio.h>
#include "items.hpp"
#ifndef meleeweapon_hpp
#define meleeweapon_hpp



class Meleeweapon: public Item {
public:
    Meleeweapon (const std::string& name, unsigned int durability, unsigned int maxcooldown, int range,int damage):Item(name,MeleeWeapon, durability, maxcooldown){
        range_=range;
        damage_=damage;
    }
    
    bool CanBeUsed() const;
    
    void Trigger();
    
    std::string &GetDescription() const;
protected:
    int range_;
    int damage_;
    
};

#endif /* meleeweapon_hpp */
