#include "../../include/users/User.h"

User::User() : userId(0) {}

User::User(unsigned id, const std::string& u, const std::string& p, const UserProfile& prof) : userId(id), username(u), password(p), profile(prof) {}

unsigned User::getUserId() const
{
    return userId;
}

const std::string& User::getUsername() const
{
    return username;
}

const std::string& User::getPassword() const
{
    return password;
}

bool User::checkPassword(const std::string& pass) const
{
    return password == pass;
}

UserProfile& User::getProfile()
{
    return profile;
}

const UserProfile& User::getProfile() const
{
    return profile;
}
