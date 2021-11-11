#include "item.hpp"


//A class that all potions inherit.
//Potions have only one point of durability.


class Potion : public Item {
    public:
    Potion(const std::string& name, const std::string& description, int effect);
    
    bool CanBeUsed() const;
    
    int Use();

    virtual int GetEffect() const = 0;

    protected:
    int effect_;
};



//Restores one health point to the player.
//Using condition: The player has missing health points.

class HealthPotion : public Potion {
    public:
    HealthPotion();
    
    int GetEffect() const;
};


//Restores all item cooldowns.
//Using condition: The player is in combat and has at least one item on cooldown.

class StaminaPotion : public Potion {
    public:
    StaminaPotion();
    
    int GetEffect() const;
};