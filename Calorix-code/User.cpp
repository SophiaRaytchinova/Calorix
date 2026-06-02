#include "User.h"
int User::nextId = 0;

User::User(const std::string& username_, const std::string& password_, const UserProfile& profile_) : username(username_), password(password_), profile(profile_)
{
    userId = nextId++;
}

double User::getHeight() const
{
    return profile.getHeight();
}

double User::getWeight() const
{
    return profile.getWeight();
}

double User::getAge() const
{
    return profile.getAge();
}

void User::registerUser(std::string username, std::string password, size_t age, size_t weigth, size_t height, std::string gender)
{

}

void User::login(std::string username, std::string password)
{

}

void User::logout()
{

}

void User::help()
{

}