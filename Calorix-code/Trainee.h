#pragma once
#include <vector>
#include <memory>
#include "Enums.h"
#include "User.h"

class Trainee : public User {
protected:
    std::vector<std::unique_ptr<FoodEntry>> foodDiary;
    std::vector<std::unique_ptr<ExerciseEntry>> exerciseDiary;
    FitnessGoal fitnessGoal;
    std::vector<std::unique_ptr<Exercise>> favouriteExercises;
    goalType goal;
    double targetValue; 
    std::string deadline;
public:
    Trainee(goalType goal, double targetValue_, std::string deadline_, const std::string& username_, const std::string& password_, const UserProfile& profile_);
    void setGoals(enum goalType, double targetValue, std::string deadline);
    void logFood(std::string foodName, int quantityGrams);
    void logExercise(std::string exerciseName, double duration);
    void viewDailySummary();
    void viewProgress();
    double calculateBMI() const;
    double calculateBMR() const;
    
};