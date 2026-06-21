#pragma once
#include <memory>
#include <vector>
#include <string>
#include "../users/User.h"

class UserRepository {
private:
    std::vector<std::unique_ptr<User>> users;
public:
    void clear();
    void addUser(std::unique_ptr<User> user);
    User* findByUsername(const std::string& username);
    const User* findByUsername(const std::string& username) const;
    bool usernameExists(const std::string& username) const;
    void removeUser(const std::string& username);
    const std::vector<std::unique_ptr<User>>& getUsers() const;
};
