#pragma once
#include <vector>
#include <string>
#include "User.h"
#include "../models/FoodEntry.h"
#include "../models/ExerciseEntry.h"
#include "../models/FitnessGoal.h"

class Trainee : public User {
private:
    std::vector<FoodEntry> foodDiary;
    std::vector<ExerciseEntry> exerciseDiary;
    std::vector<FitnessGoal> goals;
    std::vector<std::string> favoriteExercises;
public:
    Trainee();
    Trainee(unsigned userId, const std::string& username, const std::string& password, const UserProfile& profile);
    void logFood(const FoodEntry& entry) override;
    void logExercise(const ExerciseEntry& entry) override;
    void addGoal(const FitnessGoal& goal);
    void addToFavorites(const std::string& exerciseName);
    void viewFavorites() const;
    void viewDailySummary() const override;
    void viewProgress() const override;
    double calculateBMI() const;
    double calculateBMR() const;
    const std::vector<FoodEntry>& getFoodDiary() const;
    const std::vector<ExerciseEntry>& getExerciseDiary() const;
    const std::vector<FitnessGoal>& getGoals() const;
    const std::vector<std::string>& getFavorites() const;
    void help() const override;
    std::string getType() const override;
};
