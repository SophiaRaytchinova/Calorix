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
    virtual std::string getRole() const = 0;
    void help();
    virtual ~User() = default;
};