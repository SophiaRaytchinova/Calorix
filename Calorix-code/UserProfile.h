#pragma once
#include "Enums.h"
#include <string>
class UserProfile {
protected: 
    int age;
    double weight;
    double height;
    gender gender_;
    int activityLevel;
public:
    UserProfile(int age_, double weight_, double height_, gender gender_, int activityLevel_);
    int getAge() const;
    double getWeight() const;
    double getHeight() const;
    gender getGender() const;
    int getActivityLevel() const;
};