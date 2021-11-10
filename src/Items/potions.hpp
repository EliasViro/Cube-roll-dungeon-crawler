#include "item.hpp"
#include <stdio.h>
#ifndef potion_hpp
#define potion_hpp




//A class that all potions inherit.
//Potions have only one point of durability.


class Potion: public Item {
public:
    Potion(const std::string& name );
   
protected:
    bool used_;
    std::string name_;
};



//A potion that allows the player to take two turns instead of one
//immediately after drinking the potion.
//Using condition: There are enemies in the same room as the player.

class HastePotion:public Potion {
public:
    HastePotion();
    bool CanBeUsed() const ;
    
    void Trigger();
    
    std::string& GetDescription() const;
    
};


//Restores one health point to the player.
//Using condition: The player has missing health points.

class HealthPotion : public Potion {
public:
    HealthPotion();
    bool CanBeUsed() const ;
    
    void Trigger();
    
    std::string& GetDescription() const;
    
};

#endif /* potion_hpp */
