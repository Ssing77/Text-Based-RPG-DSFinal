#ifndef ENEMY_H
#define ENEMY_H

#include <string>

//enemy class definition
class Enemy {
public:
    //get enemy name, and health
    Enemy(const std::string& name, int health);
    std::string getName() const;
    int getHealth() const;
    //apply damage to enemy
    void takeDamage(int damage);

private:
    std::string name;//enemy name
    int health;//enemy health
};

#endif // ENEMY_H
