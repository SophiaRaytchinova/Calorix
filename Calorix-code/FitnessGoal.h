#pragma once
#include "Enums.h"
#include <string>
class FitnessGoal {
protected:
    goalType goal;
    double targetValue; 
    std::string deadline;
    bool isAchieved = false;
public:
    FitnessGoal(goalType goal, double targetValue, const std::string& deadline);
    void markAsAchieved();
    std::string getGoalType() const;
    double getTargetValue() const;
    std::string getDeadline() const;
    bool getIsAchieved() const;
};