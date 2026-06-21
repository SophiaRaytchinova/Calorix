#include "../../include/users/UserFactory.h"

std::unique_ptr<User> UserFactory::createTrainee(unsigned id, const std::string& u, const std::string& p, const UserProfile& pr)
{
    return std::make_unique<Trainee>(id,u,p,pr);
} 

std::unique_ptr<User> UserFactory::createAdmin(unsigned id, const std::string& u, const std::string& p, const UserProfile& pr)
{
    return std::make_unique<Admin>(id, u, p, pr);
}
