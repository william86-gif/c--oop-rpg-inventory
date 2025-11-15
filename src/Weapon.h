#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"

class Weapon : public Item {
    int damage_;
    bool equipped_ = false;
public:
    Weapon(std::string name, double weight, int value, int damage)
        : Item(std::move(name), weight, value), damage_(damage) {}

    std::string type() const override { return "Weapon"; }

    void use(Player& player) override; // defined in Weapon.cpp

    int damage() const { return damage_; }
    bool isEquipped() const { return equipped_; }
    void setEquipped(bool e) { equipped_ = e; }

    void print(std::ostream& os) const override {
        Item::print(os);
        os << ", Damage: " << damage_ << (equipped_ ? " (equipped)" : "");
    }
};

#endif // WEAPON_H
