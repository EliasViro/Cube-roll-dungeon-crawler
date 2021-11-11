#include "item.hpp"

//A class that all melee weapons inherit.
//The conditions for using a melee weapon:
//-An enemy is in range of the weapon
//-The weapon isn't on cooldown.

class MeleeWeapon : public Item {
    public:
    MeleeWeapon(const std::string& name, const std::string& description, int durability, int maxcooldown, int damage, int range, bool isstunning, bool targetseveralenemies);
    
    bool CanBeUsed() const;
    
    int Use();

    int GetDamage() const;

    int GetRange() const;

    virtual bool IsStunning() const = 0;

    virtual bool TargetSeveralEnemies() const = 0;

    protected:
    int range_;
    int damage_;
    bool isstunning_;
    bool targetseveralenemies_;
};



class ShortSword : public MeleeWeapon {
    public:
    ShortSword();

    bool IsStunning() const;

    bool TargetSeveralEemies() const;
};


class ArmingSword : public MeleeWeapon {
    public:
    ArmingSword();

    bool IsStunning() const;

    bool TargetSeveralEemies() const;
};


class LongSword : public MeleeWeapon {
    public:
    LongSword();

    bool IsStunning() const;

    bool TargetSeveralEemies() const;
};


class HandAxe : public MeleeWeapon {
    public:
    HandAxe();

    bool IsStunning() const;

    bool TargetSeveralEemies() const;
};


class BattleAxe : public MeleeWeapon {
    public:
    BattleAxe();

    bool IsStunning() const;

    bool TargetSeveralEemies() const;
};


class Mace : public MeleeWeapon {
    public:
    Mace();

    bool IsStunning() const;

    bool TargetSeveralEemies() const;
};


class WarHammer : public MeleeWeapon {
    public:
    WarHammer();

    bool IsStunning() const;

    bool TargetSeveralEemies() const;
};