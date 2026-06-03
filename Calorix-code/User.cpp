#include "User.h"
#include <iostream>

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

std::string User::getGender() const
{
    return profile.getGender();
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
    std::cout << "Available commands:" << std::endl;
    std::cout << "1. register - Register a new user" << std::endl;
    std::cout << "2. login - Log in to your account" << std::endl;
    std::cout << "3. logout - Log out of your account" << std::endl;
}