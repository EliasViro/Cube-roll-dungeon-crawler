


//A potion that allows the player to take two turns instead of one
//immediately after drinking the potion.
//Using condition: There are enemies in the same room as the player.
#include "potion.hpp"
#ifndef hastepotion_hpp
#define hastepotion_hpp

#include <stdio.h>
class HastePotion:public Potions{
public:
    HastePotion();
    bool CanBeUsed() const ;
    
    void Trigger();
    
    std::string GetDescription() const;
    
};

#endif /* hastepotion_hpp */
