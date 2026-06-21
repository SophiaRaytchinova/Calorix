#include "../../include/users/UserProfile.h"

UserProfile::UserProfile() : age(18), weight(70), height(170), gender(Gender::MALE), activityLevel(ActivityLevel::MODERATE) {}

UserProfile::UserProfile(int a, double w, double h, Gender g, ActivityLevel al) : age(a), weight(w), height(h), gender(g), activityLevel(al) {}

int UserProfile::getAge() const 
{
    return age;
} 

double UserProfile::getWeight() const
{
    return weight;
} 

double UserProfile::getHeight() const
{
    return height;
} 

Gender UserProfile::getGender() const
{
    return gender;
} 

ActivityLevel UserProfile::getActivityLevel() const
{
    return activityLevel;
}

void UserProfile::setWeight(double w)
{
    weight = w;
} 

void UserProfile::setActivityLevel(ActivityLevel v)
{
    activityLevel = v;
}

double UserProfile::calculateBMI() const
{
    double h = height / 100.0;
    return h > 0 ? weight / (h * h) : 0;
}

double UserProfile::calculateBMR() const
{
    return gender == Gender::MALE ? 10 * weight + 6.25 * height - 5 * age + 5 : 10 * weight + 6.25 * height - 5 * age - 161;
}

double UserProfile::calculateDailyCalories() const
{
    double f = 1.55;
    switch (activityLevel)
    {
        case ActivityLevel::SEDENTARY:
            f = 1.2;
            break;
        case ActivityLevel::LIGHT:
            f = 1.375;
            break;
        case ActivityLevel::MODERATE:
            f = 1.55;
            break;
        case ActivityLevel::ACTIVE:
            f = 1.725;
            break;
        case ActivityLevel::VERY_ACTIVE:
            f = 1.9;
            break;
    }
    return calculateBMR() * f;
}
