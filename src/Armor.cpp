#include "Armor.h"
#include "Player.h"
#include <iostream>

void Armor::use(Player& player) {
    if (!isEquipped()) {
        setEquipped(true);
        player.def() += defense();
        std::cout << "Equipped armor '" << name_ << "'. DEF +" << defense() << "\n";
    } else {
        setEquipped(false);
        player.def() -= defense();
        std::cout << "Unequipped armor '" << name_ << "'. DEF -" << defense() << "\n";
    }
}
