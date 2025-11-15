#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

class Player; // forward declaration

// Abstract base class: common API for all items
class Item {
protected:
    std::string name_;
    double weight_;
    int value_;
public:
    Item(std::string name, double weight, int value)
        : name_(std::move(name)), weight_(weight), value_(value) {}

    virtual ~Item() { /* virtual to ensure proper deletion via base* */ }

    // Polymorphic interface
    virtual std::string type() const = 0;
    virtual void use(Player& player) = 0;

    // Non-virtual helpers (shared for printing)
    const std::string& name() const { return name_; }
    double weight() const { return weight_; }
    int value() const { return value_; }

    // Virtual so derived types can add details
    virtual void print(std::ostream& os) const {
        os << "[" << type() << "] "
           << "Name: " << name_ << ", Weight: " << weight_
           << ", Value: " << value_;
    }
};

inline std::ostream& operator<<(std::ostream& os, const Item& it) {
    it.print(os);
    return os;
}

#endif // ITEM_H
