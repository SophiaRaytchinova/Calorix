#pragma once
#include "User.h"

class Admin : public User {
public:
    Admin();
    Admin(unsigned userId, const std::string& username, const std::string& password, const UserProfile& profile);
    void help() const override;
    std::string getType() const override;
};
