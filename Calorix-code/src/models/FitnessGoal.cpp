#include "../../include/models/FitnessGoal.h"

FitnessGoal::FitnessGoal() : goalType(GoalType::MAINTENANCE), targetValue(0), achieved(false) {}

FitnessGoal::FitnessGoal(GoalType g, double t, const Date& s, const Date& d, bool a) : goalType(g), targetValue(t), startDate(s), deadline(d), achieved(a) {}

GoalType FitnessGoal::getGoalType() const
{
    return goalType;
} 

double FitnessGoal::getTargetValue() const
{
    return targetValue;
} 

const Date& FitnessGoal::getStartDate() const
{
    return startDate;
}

const Date& FitnessGoal::getDeadline() const
{
    return deadline;
}

bool FitnessGoal::isAchieved() const
{
    return achieved;
}

void FitnessGoal::setAchieved(bool v)
{
    achieved = v;
}
