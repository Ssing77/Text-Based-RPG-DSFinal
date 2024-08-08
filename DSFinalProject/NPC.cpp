#include "NPC.h"

NPC::NPC(const std::string& name, const std::string& description)
    : name(name), description(description) {}

std::string NPC::getName() const {
    return name;
}

std::string NPC::getDescription() const {
    return description;
}

bool NPC::operator==(const NPC& other) const {
    return name == other.name && description == other.description;
}

std::ostream& operator<<(std::ostream& os, const NPC& npc) {
    os << npc.name << ": " << npc.description;
    return os;
}
