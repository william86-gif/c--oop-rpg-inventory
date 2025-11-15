#ifndef ARMOR_H
#define ARMOR_H

#include "Item.h"

class Armor : public Item {
    int defense_;
    bool equipped_ = false;
public:
    Armor(std::string name, double weight, int value, int defense)
        : Item(std::move(name), weight, value), defense_(defense) {}

    std::string type() const override { return "Armor"; }

    void use(Player& player) override; // defined in Armor.cpp

    int defense() const { return defense_; }
    bool isEquipped() const { return equipped_; }
    void setEquipped(bool e) { equipped_ = e; }

    void print(std::ostream& os) const override {
        Item::print(os);
        os << ", Defense: " << defense_ << (equipped_ ? " (equipped)" : "");
    }
};

#endif // ARMOR_H
