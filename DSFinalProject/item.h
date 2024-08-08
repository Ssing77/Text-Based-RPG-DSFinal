#pragma once

#include <string>

class Item {
public:
    Item(const std::string& name, const std::string& type, const std::string& effect);

    std::string getName() const;
    std::string getType() const; //method to get item type
    std::string getEffect() const; //method to get item effect

private:
    std::string name;
    std::string type;  //type of the item
    std::string effect; //effect of the item 
};
