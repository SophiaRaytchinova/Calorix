#include "User.h"
#include <iostream>

int User::nextId = 0;

User::User(const std::string& username_, const std::string& password_, const UserProfile& profile_) : username(username_), password(password_), profile(profile_)
{
    userId = ++nextId;
}

void User::help()
{
    std::cout << "Available commands:" << std::endl;
    std::cout << "1. register - Register a new user" << std::endl;
    std::cout << "2. login - Log in to your account" << std::endl;
    std::cout << "3. logout - Log out of your account" << std::endl;
}