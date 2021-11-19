#include "rangedweapons.hpp"


//A class that all ranged weapons inherit.
//The maximum range of any ranged weapon is 3.
//The conditions for using a ranged weapon:
//-An enemy is in range of the weapon, but not in a tile next to the 
//player and the attack of the ranged weapon can "walk" to the same tile
//as the enemy without passing walls in moves specified by the weapon's 
//range.
//-The weapon isn't on cooldown.


RangedWeapon::RangedWeapon(const std::string& name, const std::string& description, int durability, int maxcooldown, int damage, int range, bool isstunning, bool isthrown)
    : Item(name, description, RangedWeaponItem, durability, maxcooldown), damage_(damage), range_(range), isstunning_(isstunning), isthrown_(isthrown) {}

bool RangedWeapon::CanBeUsed() const {
    if ((cooldown_ == 0 && isactive_)) {
        return true;
    }
    else {
        return false;
    }
}

int RangedWeapon::Use() {
    cooldown_ = maxcooldown_;
    durability_--;
    return damage_;
}

int RangedWeapon::GetDamage() const {
    return damage_;
}

int RangedWeapon::GetRange() const {
    return range_;
}

bool RangedWeapon::IsStunning() const {
    return isstunning_;
}

bool RangedWeapon::IsThrown() const {
    return isthrown_;
}


//Cooldown 7, Damage 2. Thrown.
Javelin::Javelin() : RangedWeapon("Javelin", "A hefty throwing spear with a sharp tip.", 999, 7, 2, 3, false, true) {}


//Cooldown 7, Damage 0. Thrown. Stunning.
Bolas::Bolas() : RangedWeapon("Bolas", "A strange throwing weapon consisting of three stone weights attached to each other with rope. The weights wrap around and entangle the target it is thrown at and any enemies next to it, restricting their movement for a short while.", 999, 7, 0, 3, true, true) {}


//Cooldown 8, Damage 1.
Sling::Sling() : RangedWeapon("Sling", "A simple piece of leather meant for slinging stones, which means that the ammunition is very plentiful. It takes a while to place a new stone in it though.", 999, 8, 1, 3, false, false) {}
