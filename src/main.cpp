#include <iostream>
#include <limits>
#include <vector>

#include "Player.h"
#include "Weapon.h"
#include "Armor.h"
#include "Potion.h"

// Simple helpers for input
int readInt(const char* prompt) {
    std::cout << prompt;
    int x;
    while (!(std::cin >> x)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter an integer: ";
    }
    return x;
}

double readDouble(const char* prompt) {
    std::cout << prompt;
    double x;
    while (!(std::cin >> x)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter a number: ";
    }
    return x;
}

std::string readWord(const char* prompt) {
    std::cout << prompt;
    std::string s;
    std::cin >> s;
    return s;
}

void printMenu() {
    std::cout << "\n==== RPG Inventory ====\n"
              << "1) Add item\n"
              << "2) List items\n"
              << "3) Use item\n"
              << "4) Remove item\n"
              << "5) Show player stats\n"
              << "6) Demo: stack vs heap\n"
              << "0) Exit\n";
}

int main() {
    Player player("Hero");

    bool running = true;
    while (running) {
        printMenu();
        int choice = readInt("Choice: ");
        switch (choice) {
            case 1: {
                std::cout << "Add (1=Weapon, 2=Armor, 3=Potion): ";
                int kind; std::cin >> kind;

                std::string name = readWord("Name: ");
                double weight = readDouble("Weight: ");
                int value = readInt("Value: ");

                if (kind == 1) {
                    int dmg = readInt("Damage: ");
                    // HEAP allocation: we own and will delete in Player destructor/remove
                    player.addItem(new Weapon(name, weight, value, dmg));
                } else if (kind == 2) {
                    int def = readInt("Defense: ");
                    player.addItem(new Armor(name, weight, value, def));
                } else if (kind == 3) {
                    int heal = readInt("Heal amount: ");
                    player.addItem(new Potion(name, weight, value, heal));
                } else {
                    std::cout << "Unknown item type.\n";
                }
                break;
            }
            case 2:
                player.listItems();
                break;
            case 3: {
                if (player.size() == 0) { std::cout << "Inventory empty.\n"; break; }
                size_t idx = (size_t)readInt("Index to use: ");
                if (!player.useItem(idx)) std::cout << "Invalid index.\n";
                break;
            }
            case 4: {
                if (player.size() == 0) { std::cout << "Inventory empty.\n"; break; }
                size_t idx = (size_t)readInt("Index to remove: ");
                if (!player.removeItem(idx)) std::cout << "Invalid index.\n";
                else std::cout << "Item removed.\n";
                break;
            }
            case 5:
                player.showStats();
                break;
            case 6: {
                std::cout << "\n-- Stack vs Heap demo --\n";
                // STACK: automatic lifetime, cannot store a pointer in inventory safely
                Potion stackPotion("StackHeal", 0.1, 1, 10); // lives only in this scope
                std::cout << "Created STACK potion: " << stackPotion << "\n";
                stackPotion.use(player); // fine to use now
                std::cout << "After using stack potion -> "; player.showStats();

                // HEAP: manual lifetime via new/delete, can be stored in inventory
                Potion* heapPotion = new Potion("HeapHeal", 0.1, 1, 15);
                std::cout << "Created HEAP potion: " << *heapPotion << "\n";
                player.addItem(heapPotion); // Player now owns and will delete it
                std::cout << "-- End demo --\n";
                break;
            }
            case 0:
                running = false;
                break;
            default:
                std::cout << "Unknown choice.\n";
        }
    }

    std::cout << "Goodbye!\n";
    return 0;
}
