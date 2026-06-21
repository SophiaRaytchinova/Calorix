#pragma once
#include <string>
#include <stdexcept>

enum class Gender 
{ 
    MALE, 
    FEMALE 
};

enum class ActivityLevel 
{ 
    SEDENTARY, 
    LIGHT, 
    MODERATE, 
    ACTIVE, 
    VERY_ACTIVE 
};

enum class GoalType 
{ 
    WEIGHT_LOSS, 
    BULKING, 
    MAINTENANCE 
};

enum class MuscleGroup 
{ 
    CHEST, 
    BACK, 
    LEGS, 
    SHOULDERS, 
    ARMS, 
    CORE, 
    CARDIO 
};

enum class UserType 
{ 
    TRAINEE, 
    ADMIN 
};

std::string toString(Gender value);
std::string toString(ActivityLevel value);
std::string toString(GoalType value);
std::string toString(MuscleGroup value);

Gender genderFromString(const std::string& value);
ActivityLevel activityLevelFromString(const std::string& value);
GoalType goalTypeFromString(const std::string& value);
MuscleGroup muscleGroupFromString(const std::string& value);
