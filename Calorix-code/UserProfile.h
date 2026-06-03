#pragma once
#include "Enums.h"
#include <string>
class UserProfile {
protected: 
    int age;
    double weight;
    double height;
    gender gender;
    int activityLevel;
public:
    int getAge() const;
    double getWeight() const;
    double getHeight() const;
    std::string getGender() const;
    int getActivityLevel() const;
};