#include "../../include/users/Admin.h"
#include <iostream>

Admin::Admin() : User() {} 
Admin::Admin(unsigned id, const std::string& u, const std::string& p, const UserProfile& pr) : User(id, u, p, pr) {}
void Admin::help() const
{
    std::cout << "Admin commands:" << std::endl;
    std::cout << "block-user <username>" << std::endl;
    std::cout << "add-food <name> <calories_per_100g> <protein_per_100g> <carbs_per_100g> <fat_per_100g>" << std::endl;
    std::cout << "add-exercise <name> <calories_burned_per_hour> <muscle-group> [recommended_minutes]" << std::endl;
    std::cout << "update-food <food-name> <new-calories>" << std::endl;
    std::cout << "logout" << std::endl;
    std::cout << "help" << std::endl;
    std::cout << "end" << std::endl;
}
std::string Admin::getType() const
{
    return "Admin";
}
