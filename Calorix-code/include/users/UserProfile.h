#pragma once
#include "../models/Enums.h"

class UserProfile {
private:
    int age;
    double weight;
    double height;
    Gender gender;
    ActivityLevel activityLevel;
public:
    UserProfile();
    UserProfile(int age, double weight, double height, Gender gender, ActivityLevel activityLevel);
    int getAge() const;
    double getWeight() const;
    double getHeight() const;
    Gender getGender() const;
    ActivityLevel getActivityLevel() const;
    void setWeight(double weight);
    void setActivityLevel(ActivityLevel value);
    double calculateBMI() const;
    double calculateBMR() const;
    double calculateDailyCalories() const;
};
