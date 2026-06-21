#pragma once
#include <string>
#include "Enums.h"

class Exercise {
private:
    unsigned exerciseId;
    std::string name;
    double caloriesBurnedPerHour;
    MuscleGroup muscleGroup;
    int recommendedDurationMinutes;
public:
    Exercise();
    Exercise(unsigned exerciseId, const std::string& name, double caloriesBurnedPerHour, MuscleGroup muscleGroup, int recommendedDurationMinutes = 30);
    unsigned getExerciseId() const;
    const std::string& getName() const;
    double getCaloriesBurnedPerHour() const;
    MuscleGroup getMuscleGroup() const;
    int getRecommendedDurationMinutes() const;
};
