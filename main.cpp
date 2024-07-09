#include <iostream>
#include "Action.h"
#include "Planner.h"

int main() {
    // Define actions
    Action gatherWood("Gather Wood", 1.0f);
    gatherWood.setPrecondition("hasAxe", true);
    gatherWood.setEffect("hasWood", true);

    Action buildHouse("Build House", 5.0f);
    buildHouse.setPrecondition("hasWood", true);
    buildHouse.setEffect("hasHouse", true);

    Action findAxe("Find Axe", 2.0f);
    findAxe.setEffect("hasAxe", true);

    std::vector<Action> actions = {gatherWood, buildHouse, findAxe};

    // Define initial world state
    std::map<std::string, bool> worldState = {
        {"hasWood", false},
        {"hasAxe", false},
        {"hasHouse", false}
    };

    // Debugging output for initial state
    std::cout << "Initial World State:" << std::endl;
    for(const auto& state : worldState) {
        std::cout << state.first << " = " << state.second << std::endl;
    }

    // Define goal
    std::map<std::string, bool> goal = {{"hasHouse", true}};

    // Debugging output for goal
    std::cout << "Goal State:" << std::endl;
    for (const auto& g : goal) {
        std::cout << g.first << " = " << g.second << std::endl;
    }

    Planner planner;
    std::vector<Action> plan = planner.plan(actions, worldState, goal);

    // Output the plan
    std::cout << "Action Plan:" << std::endl;
    for (const Action& action : plan) {
        std::cout << action.getName() << std::endl;
    }

    return 0;
}