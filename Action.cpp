#include "Action.h"

Action::Action(std::string name, float cost) : name(name), cost(cost) {}

bool Action::isValid(const std::map<std::string, bool>& worldState) const {
    for (const auto& precondition : preconditions) {
        if (worldState.at(precondition.first) != precondition.second) {
            return false;
        }
    }
    return true;
}

void Action::setPrecondition(std::string key, bool value) {
    preconditions[key] = value;
}

void Action::setEffect(std::string key, bool value) {
    effects[key] = value;
}

std::map<std::string, bool> Action::getPreconditions() const {
    return preconditions;
}

std::map<std::string, bool> Action::getEffects() const {
    return effects;
}

float Action::getCost() const {
    return cost;
}

std::string Action::getName() const {
    return name;
}

// Definition of the equality operator
bool Action::operator==(const Action& other) const {
    return name == other.name;
}