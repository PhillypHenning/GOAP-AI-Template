#ifndef ACTION_H
#define ACTION_H

#include <string>
#include <map>

class Action {
public:
    Action(std::string name, float cost);

    // Check if the action's preconditions are met
    bool isValid(const std::map<std::string, bool>& worldState) const;

    // Set the preconditions and effects
    void setPrecondition(std::string key, bool value);
    void setEffect(std::string key, bool value);

    // Getters
    std::map<std::string, bool> getPreconditions() const;
    std::map<std::string, bool> getEffects() const;
    float getCost() const;
    std::string getName() const;

    // Equality operator for comparison
    bool operator==(const Action& other) const;

private:
    std::string name;
    float cost;
    std::map<std::string, bool> preconditions;
    std::map<std::string, bool> effects;
};

#endif // ACTION_H