


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

#endif /* potion_hpp */
