#ifndef POTION_H
#define POTION_H

#include "Item.h"

class Potion : public Item {
    int heal_;
    bool consumed_ = false;
public:
    Potion(std::string name, double weight, int value, int heal)
        : Item(std::move(name), weight, value), heal_(heal) {}

    std::string type() const override { return "Potion"; }

    void use(Player& player) override; // defined in Potion.cpp

    bool consumed() const { return consumed_; }

    void print(std::ostream& os) const override {
        Item::print(os);
        os << ", Heals: " << heal_ << (consumed_ ? " (consumed)" : "");
    }
};

#endif // POTION_H
