#pragma once
#include <string>
#include "UserProfile.h"

class User {
protected:
    static int nextId;
    int userId;
    std::string username;
    std::string password;
    UserProfile profile;
public:
    User(const std::string& username_, const std::string& password_, const UserProfile& profile_);
    double getHeight() const;
    double getWeight() const;
    double getAge() const;
    void registerUser(std::string username, std::string password, size_t age, size_t weigth, size_t height, std::string gender);
    void login(std::string username, std::string password);
    void logout();
    void help();
};