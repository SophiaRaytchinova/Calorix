#include "Food.h"
int Food::nextFoodId = 0;

Food::Food(const std::string& name_, int caloriesPer100g_, 
    double proteinPer100g_, double carbPer100g_, double fatPer100g_) : name(name_),
    caloriesPer100g(caloriesPer100g_), proteinPer100g(proteinPer100g_),
    carbPer100g(carbPer100g_), fatPer100g(fatPer100g_)
{
    foodId = ++nextFoodId;
}

std::string Food::getName() const
{
    return name;
}

int Food::getCaloriesPer100g() const
{
    return caloriesPer100g;
}

double Food::getProteinPer100g() const
{
    return proteinPer100g;
}

double Food::getCarbPer100g() const
{
    return carbPer100g;
}

double Food::getFatPer100g() const
{
    return fatPer100g;
}
