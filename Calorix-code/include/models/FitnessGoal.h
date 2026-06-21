#pragma once
#include "Enums.h"
#include "Date.h"

class FitnessGoal {
private:
    GoalType goalType;
    double targetValue;
    Date startDate;
    Date deadline;
    bool achieved;
public:
    FitnessGoal();
    FitnessGoal(GoalType goalType, double targetValue, const Date& startDate, const Date& deadline, bool achieved = false);
    GoalType getGoalType() const;
    double getTargetValue() const;
    const Date& getStartDate() const;
    const Date& getDeadline() const;
    bool isAchieved() const;
    void setAchieved(bool value);
};
