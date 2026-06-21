#include "../../include/repositories/UserRepository.h"
#include <algorithm>

void UserRepository::clear()
{
    users.clear();
} 

void UserRepository::addUser(std::unique_ptr<User> u)
{
    users.push_back(std::move(u));
} 

User* UserRepository::findByUsername(const std::string& n)
{
    for (auto& u:users) 
    {
        if (u->getUsername() == n) return u.get();
    }
    return nullptr;
} 

const User* UserRepository::findByUsername(const std::string& n) const
{
    for (const auto& u:users)
    {
        if (u->getUsername() == n) return u.get();
    }
    return nullptr;
} 

bool UserRepository::usernameExists(const std::string& n) const
{
    return findByUsername(n) != nullptr;
} 

void UserRepository::removeUser(const std::string& n)
{
    users.erase(std::remove_if(users.begin(), users.end(), [&n](const std::unique_ptr<User>& u) {
        return u->getUsername() == n; 
    }), users.end());
} 

const std::vector<std::unique_ptr<User>>& UserRepository::getUsers() const
{
    return users;
}