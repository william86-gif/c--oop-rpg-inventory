#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include "Item.h"

class Player {
    std::string name_;
    int hp_{100};
    int maxHp_{100};
    int atk_{5};
    int def_{0};

    // Inventory owns heap-allocated items (we delete them)
    std::vector<Item*> inventory_;

public:
    explicit Player(std::string name) : name_(std::move(name)) {}
    ~Player(); // deletes owned Item*s

    // No copying to keep ownership simple for this exercise
    Player(const Player&) = delete;
    Player& operator=(const Player&) = delete;

    // Basic stats
    int& atk() { return atk_; }
    int& def() { return def_; }
    int& hp()  { return hp_; }
    int  maxHp() const { return maxHp_; }

    void showStats() const;

    // Inventory management (manual memory control)
    void addItem(Item* it);                // takes ownership
    void listItems() const;
    bool useItem(size_t index);            // polymorphic use
    bool removeItem(size_t index);         // deletes and removes

    size_t size() const { return inventory_.size(); }
};

#endif // PLAYER_H
