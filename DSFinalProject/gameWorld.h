#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include <string>
#include "enemy.h"
//class definition for game world
class GameWorld {
public:
    GameWorld();//constrctor
    ~GameWorld();//destructor
    void createCharacter(const std::string& name);

private://self explanatory
    void startAdventure();
    void exploreForest();
    void exploreShadowyForest();
    void exploreMountain();
    void visitMeadow();
    void combatEncounter(Enemy& enemy);
    //player info
    std::string characterName;
    int playerHealth;
    int playerDamage;
};

#endif // GAMEWORLD_H
