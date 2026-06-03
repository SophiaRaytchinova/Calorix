#include "UserProfile.h"

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

std::string UserProfile::getGender() const
{
    if (gender == gender::MALE) {
        return "Male";
    } 
    else {
        return "Female";
    }
}

int UserProfile::getActivityLevel() const
{
    return activityLevel;
}