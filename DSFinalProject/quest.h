#ifndef QUEST_H
#define QUEST_H

#include <string>
#include <vector>

class Quest {
public:
    Quest(const std::string& title, const std::string& description, const std::vector<std::string>& objectives);

    std::string getTitle() const;
    std::string getDescription() const;
    std::vector<std::string> getObjectives() const;
    bool isCompleted() const;

    void addObjective(const std::string& objective);
    void markObjectiveComplete(const std::string& objective);
    void displayQuest() const;

private:
    std::string title;
    std::string description;
    std::vector<std::string> objectives;
    std::vector<bool> objectivesCompleted;
};

#endif // QUEST_H
