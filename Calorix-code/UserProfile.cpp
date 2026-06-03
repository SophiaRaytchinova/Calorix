#include "UserProfile.h"

UserProfile::UserProfile(int age_, double weight_, double height_, gender gender_, int activityLevel_) : age(age_), weight(weight_), height(height_), gender_(gender_), activityLevel(activityLevel_)
{
}

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

gender UserProfile::getGender() const
{
    return gender_;
}

int UserProfile::getActivityLevel() const
{
    return activityLevel;
}