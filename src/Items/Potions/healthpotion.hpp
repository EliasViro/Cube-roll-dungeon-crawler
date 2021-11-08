


//Restores one health point to the player.
//Using condition: The player has missing health points.
#include "potion.hpp"
#ifndef healthpotion_hpp
#define healthpotion_hpp

#include <stdio.h>
class HealthPotion:public Potions{
public:
    HealthPotion();
    bool CanBeUsed() const ;
    
    void Trigger();
    
    std::string GetDescription() const;
    
};
#endif /* healthpotion_hpp */
