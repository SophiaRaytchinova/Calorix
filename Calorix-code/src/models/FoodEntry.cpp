#include "../../include/models/FoodEntry.h"

FoodEntry::FoodEntry() : entryId(0), quantityGrams(0) {}

FoodEntry::FoodEntry(unsigned id, std::shared_ptr<Food> f, double q, const Date& d) : entryId(id), food(std::move(f)), quantityGrams(q), date(d) {}

unsigned FoodEntry::getEntryId() const 
{
    return entryId;
} 

std::shared_ptr<Food> FoodEntry::getFood() const
{
    return food;
}
double FoodEntry::getQuantityGrams() const
{
    return quantityGrams;
}
const Date& FoodEntry::getDate() const
{
    return date;
}
double FoodEntry::getCalories() const
{
    return food ? food->getCaloriesPer100g() * quantityGrams / 100.0 : 0;
}
double FoodEntry::getProtein() const
{
    return food ? food->getProteinPer100g() * quantityGrams / 100.0 : 0;
}
double FoodEntry::getCarbs() const
{
    return food ? food->getCarbsPer100g() * quantityGrams / 100.0 : 0;
}
double FoodEntry::getFat() const
{
    return food ? food->getFatPer100g() * quantityGrams / 100.0 : 0;
}
