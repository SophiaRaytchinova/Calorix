#include "FitnessGoal.h"

FitnessGoal::FitnessGoal(goalType goal, double targetValue, const std::string& deadline) 
: goal(goal), targetValue(targetValue), deadline(deadline) 
{
}

void FitnessGoal::markAsAchieved()
{
    isAchieved = true;
}

std::string FitnessGoal::getGoalType() const
{
    if (goal == goalType::WEIGHT_LOSS) {
        return "Weight loss";
    }
    else if (goal == goalType::BULKING) {
        return "Bulking";
    }
    else {
        return "Maintenance";
    }
}

double FitnessGoal::getTargetValue() const
{
    return targetValue;
}

std::string FitnessGoal::getDeadline() const
{
    return deadline;
}

bool FitnessGoal::getIsAchieved() const
{
    return isAchieved;
}
