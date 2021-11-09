


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
    Meleeweapon (const std::string& name, unsigned int durability, unsigned int maxcooldown,int damage):Item(name,MeleeWeapon, durability, maxcooldown){
        range_=1;
        damage_=damage;
        
    }
    
    
    bool CanBeUsed() const;
    
    void Trigger();
    
    std::string GetDescription() const ;
    protected:
    int range_;
    int damage_;
    

    
};



//A melee weapon.
//Range - 1, damage - 2, max cooldown - 6, durability - 999

class Axe : public Meleeweapon {
    public:
    Axe();

};


//A basic melee weapon with improved attack speed.
//Range - 1, damage - 1, max cooldown - 3, durability - 999

#include <stdio.h>
class Dagger : public Meleeweapon {
    public:
    Dagger ();
};



//A powerful melee weapon that hits all enemies in the attack range.
//Range - 1, damage - 2, max cooldown - 6, durability - 999

class GreatSword:public Meleeweapon {
    public:
    GreatSword();
    
};



//A melee weapon.
//Range - 1, damage - 2, max cooldown - 5, durability - 999

class LongSword : public Meleeweapon {
    public:
    LongSword();
    
};

//A basic melee weapon.
//Range - 1, damage - 1, max cooldown - 4, durability - 999

class Shortsword : public Meleeweapon {
    public:
    Shortsword();
};


#endif /* meleeweapon_hpp */
