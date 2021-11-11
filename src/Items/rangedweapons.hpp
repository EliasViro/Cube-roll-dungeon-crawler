#include "item.hpp"


//A class that all ranged weapons inherit.
//The maximum range of any ranged weapon is 3.
//The conditions for using a ranged weapon:
//-An enemy is in range of the weapon, but not in a tile next to the 
//player and the attack of the ranged weapon can "walk" to the same tile
//as the enemy without passing walls in moves specified by the weapon's 
//range.
//-The weapon isn't on cooldown.


class RangedWeapon : public Item {
    public:
    RangedWeapon(const std::string& name, const std::string& description, int durability, int maxcooldown, int damage, int range, bool isstunning, bool isthrown);
    
    bool CanBeUsed() const;
    
    int Use();

    int GetDamage() const;

    int GetRange() const;

    virtual bool IsStunning() const = 0;

    virtual bool IsThrown() const = 0;

    protected:
    int range_;
    int damage_;
    bool isstunning_;
    bool isthrown_;
};


class Javelin : public RangedWeapon {
    public:
    Javelin();

    bool IsStunning() const;

    bool IsThrown() const;
};


class Bolas : public RangedWeapon {
    public:
    Bolas();

    bool IsStunning() const;

    bool IsThrown() const;
};


class Sling : public RangedWeapon {
    public:
    Sling();

    bool IsStunning() const;

    bool IsThrown() const;
};