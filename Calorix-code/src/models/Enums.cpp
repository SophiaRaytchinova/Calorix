#include "../../include/models/Enums.h"

std::string toString(Gender value) {
    switch (value) {
        case Gender::MALE: 
            return "MALE";
        case Gender::FEMALE: 
            return "FEMALE";
    }
    throw std::invalid_argument("Invalid gender value");
}

std::string toString(ActivityLevel value) {
    switch (value) {
        case ActivityLevel::SEDENTARY: 
            return "SEDENTARY";
        case ActivityLevel::LIGHT: 
            return "LIGHT";
        case ActivityLevel::MODERATE: 
            return "MODERATE";
        case ActivityLevel::ACTIVE: 
            return "ACTIVE";
        case ActivityLevel::VERY_ACTIVE: 
            return "VERY_ACTIVE";
    }
    throw std::invalid_argument("Invalid activity level value");
}

std::string toString(GoalType value) {
    switch (value) {
        case GoalType::WEIGHT_LOSS: 
            return "WEIGHT_LOSS";
        case GoalType::BULKING: 
            return "BULKING";
        case GoalType::MAINTENANCE: 
            return "MAINTENANCE";
    }
    throw std::invalid_argument("Invalid goal type value");
}

std::string toString(MuscleGroup value) {
    switch (value) {
        case MuscleGroup::CHEST: 
            return "CHEST";
        case MuscleGroup::BACK: 
            return "BACK";
        case MuscleGroup::LEGS: 
            return "LEGS";
        case MuscleGroup::SHOULDERS: 
            return "SHOULDERS";
        case MuscleGroup::ARMS: 
            return "ARMS";
        case MuscleGroup::CORE: 
            return "CORE";
        case MuscleGroup::CARDIO: return "CARDIO";
    }
    throw std::invalid_argument("Invalid muscle group value");
}

Gender genderFromString(const std::string& value) {
    if (value == "MALE") 
    {
        return Gender::MALE;
    }
    if (value == "FEMALE") 
    {
        return Gender::FEMALE;
    }
    throw std::invalid_argument("Invalid gender. Use MALE or FEMALE.");
}

ActivityLevel activityLevelFromString(const std::string& value) {
    if (value == "SEDENTARY") 
    {
        return ActivityLevel::SEDENTARY;
    }
    if (value == "LIGHT") 
    {
        return ActivityLevel::LIGHT;
    }
    if (value == "MODERATE") 
    {
        return ActivityLevel::MODERATE;
    }
    if (value == "ACTIVE") 
    {
        return ActivityLevel::ACTIVE;
    }
    if (value == "VERY_ACTIVE") 
    {
        return ActivityLevel::VERY_ACTIVE;
    }
    throw std::invalid_argument("Invalid activity level.");
}

GoalType goalTypeFromString(const std::string& value) {
    if (value == "WEIGHT_LOSS") 
    {
        return GoalType::WEIGHT_LOSS;
    }
    if (value == "BULKING") 
    {
        return GoalType::BULKING;
    }
    if (value == "MAINTENANCE") 
    {
        return GoalType::MAINTENANCE;
    }
    throw std::invalid_argument("Invalid goal type. Use WEIGHT_LOSS, BULKING or MAINTENANCE.");
}

MuscleGroup muscleGroupFromString(const std::string& value) {
    if (value == "CHEST") 
    {
        return MuscleGroup::CHEST;
    }
    if (value == "BACK") 
    {
        return MuscleGroup::BACK;
    }
    if (value == "LEGS") 
    {
        return MuscleGroup::LEGS;
    }
    if (value == "SHOULDERS") 
    {
        return MuscleGroup::SHOULDERS;
    }
    if (value == "ARMS") 
    {
        return MuscleGroup::ARMS;
    }
    if (value == "CORE") 
    {
        return MuscleGroup::CORE;
    }
    if (value == "CARDIO") 
    {
        return MuscleGroup::CARDIO;
    }
    throw std::invalid_argument("Invalid muscle group.");
}
