#include "meleeweapons.hpp"


//A class that all melee weapons inherit.
//The conditions for using a melee weapon:
//-An enemy is in range of the weapon
//-The weapon isn't on cooldown.

MeleeWeapon::MeleeWeapon(const std::string& name, const std::string& description, int durability, int maxcooldown, int damage, int range, bool isstunning, bool targetseveralenemies)
    : Item(name, description, MeleeWeaponItem, durability, maxcooldown), damage_(damage), range_(range), isstunning_(isstunning), targetseveralenemies_(targetseveralenemies) {}

bool MeleeWeapon::CanBeUsed() const {
    if ((cooldown_ == 0 && isactive_)) {
        return true;
    }
    else {
        return false;
    }
}

int MeleeWeapon::Use() {
    cooldown_ = maxcooldown_;
    durability_--;
    return damage_;
}

int MeleeWeapon::GetDamage() const {
    return damage_;
}

int MeleeWeapon::GetRange() const {
    return range_;
}



//Cooldown 3, Damage 1.
ShortSword::ShortSword() : MeleeWeapon("Shortsword", "A short and sturdy bladed weapon with a comfortable grip.", 999, 3, 1, 1, false, false) {}
bool ShortSword::IsStunning() const { return isstunning_; }
bool ShortSword::TargetSeveralEemies() const { return targetseveralenemies_; }

//Cooldown 5, Damage 1. Hits several enemies.
ArmingSword::ArmingSword() : MeleeWeapon("Arming sword", "A medium sized single-handed sword that can cut down several enemies with a single swing.", 999, 5, 1, 1, false, true) {}
bool ArmingSword::IsStunning() const { return isstunning_; }
bool ArmingSword::TargetSeveralEemies() const { return targetseveralenemies_; }

//Cooldown 6, Damage 2. Hits several enemies.
LongSword::LongSword() : MeleeWeapon("Longsword", "A large two-handed sword that can cut down multiple enemies with a single wide swing.", 999, 6, 2, 1, false, true) {}
bool LongSword::IsStunning() const { return isstunning_; }
bool LongSword::TargetSeveralEemies() const { return targetseveralenemies_; }

//Cooldown 5, Damage 2.
HandAxe::HandAxe() : MeleeWeapon("Handaxe", "A simple one-handed axe. Quite hefty.", 999, 5, 2, 1, false, false) {}
bool HandAxe::IsStunning() const { return isstunning_; }
bool HandAxe::TargetSeveralEemies() const { return targetseveralenemies_; }

//Cooldown 6, Damage 3.
BattleAxe::BattleAxe() : MeleeWeapon("Battleaxe", "A large axe with a massive head and a long handle. Cuts through almost anything.", 999, 6, 3, 1, false, false) {}
bool BattleAxe::IsStunning() const { return isstunning_; }
bool BattleAxe::TargetSeveralEemies() const { return targetseveralenemies_; }

//Cooldown 5, Damage 1. Stuns targets.
Mace::Mace() : MeleeWeapon("Mace", "A simple mace with a metallic weight at the end of a wooden handle. Stuns enemies.", 999, 5, 1, 1, true, false) {}
bool Mace::IsStunning() const { return isstunning_; }
bool Mace::TargetSeveralEemies() const { return targetseveralenemies_; }

//Cooldown 6, Damage 2. Stuns targets.
WarHammer::WarHammer() : MeleeWeapon("Warhammer", "A hammer specifically designed for cracking skulls on the battlefield. Stuns enemies.", 999, 6, 2, 1, true, false) {}
bool WarHammer::IsStunning() const { return isstunning_; }
bool WarHammer::TargetSeveralEemies() const { return targetseveralenemies_; }

