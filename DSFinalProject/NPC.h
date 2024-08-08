#ifndef NPC_H
#define NPC_H

#include <string>
#include <iostream>

class NPC {
public:
    NPC(const std::string& name, const std::string& description);
    std::string getName() const;
    std::string getDescription() const;
    bool operator==(const NPC& other) const;

    friend std::ostream& operator<<(std::ostream& os, const NPC& npc);

private:
    std::string name;
    std::string description;
};

#endif // NPC_H
