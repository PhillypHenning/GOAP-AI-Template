#include "Planner.h"
#include <queue>
#include <algorithm>
#include <iostream>

Planner::Planner() {}

// A helper function to estimate the "distance" from the current state to the goal state.
int heuristic(const std::map<std::string, bool>& state, const std::map<std::string, bool>& goal) {
    int h = 0;
    for (const auto& g : goal) {
        if (state.at(g.first) != g.second) {
            h++;
        }
    }
    return h;
}

std::vector<Action> Planner::plan(std::vector<Action>& actions, 
                                  std::map<std::string, bool>& worldState, 
                                  std::map<std::string, bool>& goal) {
    std::vector<Action> plan;

    while (!isGoalReached(goal, worldState)) {
        std::vector<Action> availableActions;

        // Filter out actions that can't be performed (preconditions not met)
        std::cout << "Filtering actions based on current world state" << std::endl;
        for (Action& action : actions) {
            if (action.isValid(worldState)) {
                availableActions.push_back(action);
                std::cout << "Available: " << action.getName() << std::endl;
            } else {
                std::cout << "Not available: " << action.getName() << std::endl;
            }
        }

        if (availableActions.empty()) {
            std::cout << "No available actions left; unable to achieve goal." << std::endl;
            return {}; // Return empty plan if no actions left
        }

        // Enhance the selection logic to consider a heuristic
        Action nextAction = *std::min_element(availableActions.begin(), availableActions.end(),
            [&](Action& a, Action& b) {
                // Compute the resulting state if action `a` is applied
                std::map<std::string, bool> nextStateA = worldState;
                for (const auto& effect : a.getEffects()) {
                    nextStateA[effect.first] = effect.second;
                }

                // Compute the resulting state if action `b` is applied
                std::map<std::string, bool> nextStateB = worldState;
                for (const auto& effect : b.getEffects()) {
                    nextStateB[effect.first] = effect.second;
                }

                // Estimate the "distance" to goal for resulting states
                int heuristicA = heuristic(nextStateA, goal);
                int heuristicB = heuristic(nextStateB, goal);

                // Tie-breaker: prefer actions based on cost if heuristic values are the same
                if (heuristicA == heuristicB) {
                    return a.getCost() < b.getCost();
                }

                return heuristicA < heuristicB;
            }
        );

        // Debugging output
        std::cout << "Selected Action: " << nextAction.getName() << " with cost " << nextAction.getCost() << std::endl;

        // Apply the action's effects to the world state
        for (const auto& effect : nextAction.getEffects()) {
            worldState[effect.first] = effect.second;
            std::cout << "Effect applied: " << effect.first << " = " << effect.second << std::endl;
        }

        // Add the action to the plan
        plan.push_back(nextAction);
    }

    std::cout << "Goal reached!" << std::endl;
  
    return plan;
}

bool Planner::isGoalReached(const std::map<std::string, bool>& goal, 
                            const std::map<std::string, bool>& state) {
    for (const auto& condition : goal) {
        if (state.at(condition.first) != condition.second) {
            return false;
        }
    }
    return true;
}