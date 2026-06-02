#pragma once

class UserProfile {
protected: 
    int age;
    double weight;
    double height;
    bool gender; // 1 male 0 female
    int activityLevel;
public:
    int getAge() const;
    double getWeight() const;
    double getHeight() const;
    bool getGender() const;
    int getActivityLevel() const;
};