#include "item.h"

Item::Item(const std::string& name, const std::string& type, const std::string& effect)
    : name(name), type(type), effect(effect) {}

std::string Item::getName() const {
    return name;
}

std::string Item::getType() const {
    return type;
}

std::string Item::getEffect() const {
    return effect;
}
