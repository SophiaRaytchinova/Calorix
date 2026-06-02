#include "Trainee.h"

Trainee::Trainee(goalType goal, double targetValue_, std::string deadline_, 
    const std::string& username_, const std::string& password_, 
    const UserProfile& profile_) : User(username_, password_, profile_)
{
    goal = goal;
    targetValue = targetValue_;
    deadline = deadline_;
}

void Trainee::setGoals(goalType, double targetValue, std::string deadline)
{

}

void Trainee::logFood(std::string foodName, int quantityGrams)
{
}

void Trainee::logExercise(std::string exerciseName, double duration)
{
}

void Trainee::viewDailySummary()
{
}

void Trainee::viewProgress()
{
}

double Trainee::calculateBMI() const
{
    double heightInMeters = profile.getHeight() / 100.0;
    return profile.getWeight() / (heightInMeters * heightInMeters);
}

double Trainee::calculateBMR() const
{
    if (profile.getGender() == 1) { // 1 male 0 female
        return 10 * profile.getWeight() + 6.25 * profile.getHeight() - 5 * profile.getAge() + 5;
    } else {
        return 10 * profile.getWeight() + 6.25 * profile.getHeight() - 5 * profile.getAge() - 161;
    }
}