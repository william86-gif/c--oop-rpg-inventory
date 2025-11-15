#include "Weapon.h"
#include "Player.h"
#include <iostream>

void Weapon::use(Player& player) {
    if (!isEquipped()) {
        setEquipped(true);
        player.atk() += damage();
        std::cout << "Equipped weapon '" << name_ << "'. ATK +" << damage() << "\n";
    } else {
        setEquipped(false);
        player.atk() -= damage();
        std::cout << "Unequipped weapon '" << name_ << "'. ATK -" << damage() << "\n";
    }
}
