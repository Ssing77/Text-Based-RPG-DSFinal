#pragma once

#include <string>
#include <vector>
#include "item.h"
#include "enemy.h"

class Player {
public:
    Player();
    void createCharacter();
    void attack(Enemy& enemy);
    void useItem(Item& item);
    void saveGame();
    void loadGame();

private:
    std::string name;
    int health;
    std::vector<Item> inventory; // Assuming inventory is a vector of items
};
