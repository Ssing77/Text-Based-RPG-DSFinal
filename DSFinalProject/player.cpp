#include "player.h"
#include "item.h"
#include <iostream>
#include <fstream>
#include "enemy.h"

Player::Player() : health(100) {}

void Player::createCharacter() {
    std::cout << "Enter character name: ";
    std::cin >> name;
    std::cout << "Character " << name << " created!" << std::endl;
}

void Player::attack(Enemy& enemy) {
    std::cout << "Attacking " << enemy.getName() << "!" << std::endl;
    while (enemy.getHealth() > 0 && health > 0) {
        enemy.takeDamage(10);
        std::cout << enemy.getName() << " has " << enemy.getHealth() << " health remaining." << std::endl;
        if (enemy.getHealth() > 0) {
            health -= 5;
            std::cout << "You have " << health << " health remaining." << std::endl;
        }
    }
    if (health <= 0) {
        std::cout << "You have been defeated!" << std::endl;
    }
    else {
        std::cout << enemy.getName() << " has been defeated!" << std::endl;
    }
}

void Player::useItem(Item& item) {
    if (item.getType() == "heal") {
        // Assuming getEffect returns an integer value
        int effect = std::stoi(item.getEffect()); // Convert effect to integer
        health += effect;
        std::cout << "Used " << item.getName() << ". Health is now " << health << "." << std::endl;
    }
}

void Player::saveGame() {
    std::ofstream saveFile("savegame.txt");
    if (saveFile.is_open()) {
        saveFile << name << std::endl;
        saveFile << health << std::endl;
        // Save inventory and current quest details
        saveFile.close();
        std::cout << "Game saved successfully." << std::endl;
    }
    else {
        std::cerr << "Unable to save game." << std::endl;
    }
}

void Player::loadGame() {
    std::ifstream loadFile("savegame.txt");
    if (loadFile.is_open()) {
        loadFile >> name;
        loadFile >> health;
        // Load inventory and current quest details
        loadFile.close();
        std::cout << "Game loaded successfully." << std::endl;
    }
    else {
        std::cerr << "Unable to load game." << std::endl;
    }
}
