#include "quest.h"
#include <iostream>

// Constructor
Quest::Quest(const std::string& title, const std::string& description, const std::vector<std::string>& objectives)
    : title(title), description(description), objectives(objectives), objectivesCompleted(objectives.size(), false) {}

// Getters
std::string Quest::getTitle() const {
    return title;
}

std::string Quest::getDescription() const {
    return description;
}

std::vector<std::string> Quest::getObjectives() const {
    return objectives;
}

bool Quest::isCompleted() const {
    for (bool completed : objectivesCompleted) {
        if (!completed) {
            return false;
        }
    }
    return true;
}

// Add an objective to the quest
void Quest::addObjective(const std::string& objective) {
    objectives.push_back(objective);
    objectivesCompleted.push_back(false);
}

// Mark an objective as completed
void Quest::markObjectiveComplete(const std::string& objective) {
    for (size_t i = 0; i < objectives.size(); ++i) {
        if (objectives[i] == objective) {
            objectivesCompleted[i] = true;
            break;
        }
    }
}

// Display quest details
void Quest::displayQuest() const {
    std::cout << "Quest: " << title << std::endl;
    std::cout << description << std::endl;
    std::cout << "Objectives:" << std::endl;
    for (size_t i = 0; i < objectives.size(); ++i) {
        std::cout << (objectivesCompleted[i] ? "[X] " : "[ ] ") << objectives[i] << std::endl;
    }
    std::cout << (isCompleted() ? "Quest Completed!" : "Quest Incomplete") << std::endl;
}
