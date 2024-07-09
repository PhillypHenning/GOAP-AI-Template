#ifndef PLANNER_H
#define PLANNER_H

#include "Action.h"
#include <vector>
#include <string>
#include <map>

class Planner {
public:
    Planner();
    std::vector<Action> plan(std::vector<Action>& actions, 
                             std::map<std::string, bool>& worldState, 
                             std::map<std::string, bool>& goal);

private:
    bool isGoalReached(const std::map<std::string, bool>& goal, 
                       const std::map<std::string, bool>& state);
};

#endif // PLANNER_H