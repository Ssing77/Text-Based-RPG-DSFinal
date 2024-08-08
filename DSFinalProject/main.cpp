/*
* Sahajpreet Singh
* DSFinal.sln
* 7/14/2024
*/
#include <iostream>
#include <string>
#include "player.h"
#include "gameWorld.h"

//function prototypes
void displayMainMenu();
void handleMainMenuChoice(GameWorld& gameWorld);
void gameLoop(Player& player, GameWorld& gameWorld);

int main() {
    GameWorld gameWorld;
    Player player;

    //main menu
    bool gameRunning = true;
    while (gameRunning) {
        displayMainMenu();
        int choice;
        std::cin >> choice;
        switch (choice) {
        case 0:
            gameRunning = false;
            break;
        case 1:
            handleMainMenuChoice(gameWorld);
            gameLoop(player, gameWorld);
            break;
        case 2:
            player.loadGame();
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    std::cout << "Thank you for playing Adventure Quest!" << std::endl;
    return 0;
}

void displayMainMenu() {
    std::cout << "Adventure Quest Main Menu" << std::endl;
    std::cout << "1. Create Character" << std::endl;
    std::cout << "2. Load Game" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}
//entering yor name
void handleMainMenuChoice(GameWorld& gameWorld) {
    std::string name;
    std::cout << "Enter character name: ";
    std::cin >> name;
    gameWorld.createCharacter(name);

}

void gameLoop(Player& player, GameWorld& gameWorld) {
    std::string command;
    while (true) {
        std::cout << "> ";
        std::cin >> command;

        if (command == "exit") {
            break;
        } else if (command == "save") {
            player.saveGame();
        } else if (command == "attack") {
            Enemy enemy("Goblin", 30);
            player.attack(enemy);
        } else if (command == "use") {

            Item potion("Health Potion", "heal", "20"); 
            player.useItem(potion);
        } else {
            std::cout << "Unknown command." << std::endl;
        }
    }
}
