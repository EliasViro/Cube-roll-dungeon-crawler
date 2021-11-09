


//A class that all potions inherit.
//Potions have only one point of durability.
#include "items.hpp"
#ifndef potion_hpp
#define potion_hpp

#include <stdio.h>

class Potions: public Item {
public:
    Potions(const std::string& name );
   
protected:
    bool used_;
    std::string name_;
};



//A potion that allows the player to take two turns instead of one
//immediately after drinking the potion.
//Using condition: There are enemies in the same room as the player.

class HastePotion:public Potions{
public:
    HastePotion();
    bool CanBeUsed() const ;
    
    void Trigger();
    
    std::string GetDescription() const;
    
};


//Restores one health point to the player.
//Using condition: The player has missing health points.

class HealthPotion:public Potions{
public:
    HealthPotion();
    bool CanBeUsed() const ;
    
    void Trigger();
    
    std::string GetDescription() const;
    
};

#endif /* potion_hpp */
