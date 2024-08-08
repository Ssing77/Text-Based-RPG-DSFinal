#include "gameWorld.h"
#include "item.h"
#include "enemy.h"
#include <iostream>

GameWorld::GameWorld() {
    //initialize game world
}

GameWorld::~GameWorld() {
    //clean up resources if needed
}

void GameWorld::createCharacter(const std::string& name) {
    //create the character
    characterName = name;
    std::cout << "Character " << characterName << " created!" << std::endl;

    //start the adventure automatically after character creation
    startAdventure();
}

void GameWorld::startAdventure() {
    std::cout << "Welcome to the Adventure Quest, " << characterName << "!" << std::endl;

    std::cout << "You are suddenly abducted by octopus aliens and find yourself on their spaceship, trapped in a cold metallic cell." << std::endl;
    std::cout << "You overhear the aliens discussing a threat from dragon-riding red orcs attacking their ship." << std::endl;
    std::cout << "As the ship shakes from the battle, you manage to escape your cell and find yourself on the ship's bridge." << std::endl;
    std::cout << "With the ship in chaos, you steal a space suit and make your way to an escape pod." << std::endl;
    std::cout << "You land on a distant planet and discover you have been infected with Octonitus, a disease that will soon turn you into a thrall of the octopus aliens." << std::endl;
    std::cout << "To cure yourself, you must embark on a quest to defeat the Octopus Overlord and cleanse yourself of the disease." << std::endl;
    std::cout << "REMINDER: YOU ARE VERY WEAK IN YOUR INFECTED STATE. EVERYTHING WILL DO MASSIVE DAMAGE. REMEMBER TO USE YOUR POTIONS." << std::endl;

    //linear adventure path
    exploreForest();
}

void GameWorld::exploreForest() {
    std::cout << "You find yourself at the edge of a dense forest to the north, filled with vicious goblins and hidden traps. " << std::endl;

    //combat encounter with goblins
    Enemy goblin("Goblin", 30);
    combatEncounter(goblin);

    std::cout << "After defeating the goblins, you find a hidden stash in the forest containing a Healing Potion and a map." << std::endl;
    std::cout << "You decide to move on to the next part of your journey." << std::endl;

    exploreShadowyForest();
}

void GameWorld::exploreShadowyForest() {
    std::cout << "You enter the shadowy forest to the east, where dark shades lurk and magical phenomena occur." << std::endl;

    //special encounter(was supposed to be rare, but I plan to make the game a real game in the future
    std::cout << "As you traverse the forest, you encounter a mysterious figure who looks a lot like a hobo. He says his name is Honbo(creative I know)." << std::endl;
    std::cout << "He offers you a singular healing potion. that can help you in your battles ahead." << std::endl;
    std::cout << "He says, 'This healing potion will always stay replenished. This is because the programmer of this game didn't know how to program health potions.'" << std::endl;
    std::cout << "'But think of it as a magical excuse.'" << std::endl;
    std::cout << "You thank him, feeling weird about his comments on this 'porg hammer' and continue your journey." << std::endl;

    //combat encounter with dark shades
    Enemy darkShade("Dark Shade", 40);
    combatEncounter(darkShade);

    std::cout << "After defeating the dark shades, you find yourself at the foot of a treacherous mountain range to the south." << std::endl;
    std::cout << "You decide to move on to the final part of your journey." << std::endl;

    exploreMountain();
}

void GameWorld::exploreMountain() {
    std::cout << "You start climbing the mountain trail. The path is steep and the air gets thinner as you ascend." << std::endl;

    //special encounter
    std::cout << "You come across a cave where you meet a fierce warrior who resembles a goat. He looks like he got hit in the head so often that he grew horns." << std::endl;
    std::cout << "He challenges you to a duel to test your strength." << std::endl;

    //combat encounter with goat-man
    Enemy warrior("Warrior", 100);
    combatEncounter(warrior);

    std::cout << "After proving your strength, the warrior gives you a powerful sword and wishes you luck in your quest." << std::endl;

    //final battle with the Octopus Overlord
    std::cout << "At the peak of the mountain, you confront the Octopus Overlord." << std::endl;
    Enemy octopusOverlord("Octopus Overlord", 200);
    combatEncounter(octopusOverlord);

    std::cout << "Congratulations! You have defeated the Octopus Overlord and cured yourself of Octonitus." << std::endl;
    std::cout << "You are now free to live your life without the threat of becoming a thrall. Thank you for playing Adventure Quest! P.S. This game is no where near complete." << std::endl;
}

void GameWorld::combatEncounter(Enemy& enemy) {
    int playerHealth = 100;
    while (enemy.getHealth() > 0 && playerHealth > 0) {
        std::cout << "You encounter a " << enemy.getName() << " with " << enemy.getHealth() << " health." << std::endl;
        std::cout << "Your health: " << playerHealth << std::endl;
        std::cout << "Do you want to (1) attack, (2) use potion, or (3) flee? ";
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "You attack the " << enemy.getName() << "!" << std::endl;
            enemy.takeDamage(10);
            if (enemy.getHealth() > 0) {
                std::cout << "The " << enemy.getName() << " attacks you back!" << std::endl;
                playerHealth -= 60;
            }
        }
        else if (choice == 2) {
            std::cout << "You use a Healing Potion." << std::endl;
            playerHealth += 20;
            std::cout << "Your health is now " << playerHealth << "." << std::endl;

            // Enemy heals
            int enemyHealAmount = 10; // or any amount you want the enemy to heal
            enemy.takeDamage(-enemyHealAmount); // negative damage to heal
            std::cout << "You give the enemy a chance to heal as well." << std::endl;
            std::cout << enemy.getName() << " heals for " << enemyHealAmount << " health points." << std::endl;
            std::cout << enemy.getName() << "'s health is now " << enemy.getHealth() << "." << std::endl;
        }

        else if (choice == 3) {
            std::cout << "You flee from the " << enemy.getName() << ". You trip over a rock, and land on your head. GAME OVER." << std::endl;
            exit(0);
        }
        else {
            std::cout << "Invalid choice. You lose your turn." << std::endl;
        }
    }

    if (playerHealth <= 0) {
        std::cout << "You have been defeated by the " << enemy.getName() << "." << std::endl;
        std::cout << "Game Over." << std::endl;
        exit(0);
    }
    else {
        std::cout << "You have defeated the " << enemy.getName() << "!" << std::endl;
    }
}
