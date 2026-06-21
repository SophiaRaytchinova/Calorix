#include "../../include/repositories/FoodRepository.h"
#include <algorithm>

void FoodRepository::clear()
{
    foods.clear();
} 

void FoodRepository::addFood(const Food& f) 
{ 
    if (exists(f.getName())) 
    {
        return;
    }
    foods.push_back(std::make_shared<Food>(f));
} 

bool FoodRepository::exists(const std::string& n) const
{
    return findFood(n) != nullptr;
}

std::shared_ptr<Food> FoodRepository::findFood(const std::string& n) const
{
    for (const auto& f: foods)
    {
        if (f->getName() == n)
        {
            return f;
        }
    }
    return nullptr;
}

void FoodRepository::updateFoodCalories(const std::string& n, double c)
{
    auto f = findFood(n);
    if (f)
    {
        f->setCalories(c);
    }
}

const std::vector<std::shared_ptr<Food>>& FoodRepository::getFoods() const
{
    return foods;
}