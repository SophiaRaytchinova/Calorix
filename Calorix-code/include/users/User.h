#pragma once
#include <string>
#include "UserProfile.h"
#include "../models/FoodEntry.h"
#include "../models/ExerciseEntry.h"

class User {
protected:
    unsigned userId;
    std::string username;
    std::string password;
    UserProfile profile;
public:
    User();
    User(unsigned userId, const std::string& username, const std::string& password, const UserProfile& profile);
    virtual ~User() = default;
    unsigned getUserId() const;
    const std::string& getUsername() const;
    const std::string& getPassword() const;
    bool checkPassword(const std::string& pass) const;
    UserProfile& getProfile();
    const UserProfile& getProfile() const;
    virtual void help() const = 0;
    virtual std::string getType() const = 0;
    virtual void logFood(const FoodEntry&) {}
    virtual void logExercise(const ExerciseEntry&) {}
    virtual void viewDailySummary() const {}
    virtual void viewProgress() const {}
};
