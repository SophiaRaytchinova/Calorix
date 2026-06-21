#include "../../include/models/Exercise.h"

Exercise::Exercise() : exerciseId(0), caloriesBurnedPerHour(0), muscleGroup(MuscleGroup::CARDIO), recommendedDurationMinutes(30) {}

Exercise::Exercise(unsigned id, const std::string& n, double c, MuscleGroup m, int d) : exerciseId(id), name(n), caloriesBurnedPerHour(c), muscleGroup(m), recommendedDurationMinutes(d) {}

unsigned Exercise::getExerciseId() const
{
    return exerciseId;
}

const std::string& Exercise::getName() const
{
    return name;
}

double Exercise::getCaloriesBurnedPerHour() const
{
    return caloriesBurnedPerHour;
}

MuscleGroup Exercise::getMuscleGroup() const
{
    return muscleGroup;
}

int Exercise::getRecommendedDurationMinutes() const
{
    return recommendedDurationMinutes;
}
