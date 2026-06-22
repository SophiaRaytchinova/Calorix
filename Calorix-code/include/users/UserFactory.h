#pragma once
#include <memory>
#include "User.h"
#include "Trainee.h"
#include "Admin.h"

class UserFactory {
public:
    static std::unique_ptr<User> createTrainee(
        unsigned id,
        const std::string& username,
        const std::string& password,
        const UserProfile& profile
    );

    static std::unique_ptr<User> createAdmin(
        unsigned id,
        const std::string& username,
        const std::string& password,
        const UserProfile& profile
    );
};