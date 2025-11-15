#include "Player.h"
#include <iostream>

Player::~Player() {
    // Free all heap-allocated items we own
    for (Item* it : inventory_) {
        delete it;
    }
}

void Player::showStats() const {
    std::cout << "Player: " << name_
              << " | HP: " << hp_ << "/" << maxHp_
              << " | ATK: " << atk_
              << " | DEF: " << def_
              << "\n";
}

void Player::addItem(Item* it) {
    inventory_.push_back(it);
    std::cout << "Added: " << *it << "\n";
}

void Player::listItems() const {
    if (inventory_.empty()) {
        std::cout << "(Inventory empty)\n";
        return;
    }
    for (size_t i = 0; i < inventory_.size(); ++i) {
        std::cout << i << ": " << *inventory_[i] << "\n";
    }
}

bool Player::useItem(size_t index) {
    if (index >= inventory_.size()) return false;
    inventory_[index]->use(*this); // Polymorphic call
    return true;
}

bool Player::removeItem(size_t index) {
    if (index >= inventory_.size()) return false;
    delete inventory_[index];
    inventory_.erase(inventory_.begin() + static_cast<long>(index));
    return true;
}
