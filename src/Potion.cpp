#include "Potion.h"
#include "Player.h"
#include <algorithm>
#include <iostream>

void Potion::use(Player& player) {
    if (consumed_) {
        std::cout << "Potion '" << name_ << "' is already consumed.\n";
        return;
    }
    consumed_ = true;
    int before = player.hp();
    player.hp() = std::min(player.hp() + (int)std::max(0, heal_), player.maxHp());
    std::cout << "Drank potion '" << name_ << "'. HP " << before << " -> " << player.hp() << "\n";
}
