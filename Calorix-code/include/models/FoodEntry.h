#pragma once
#include <memory>
#include "Food.h"
#include "Date.h"

class FoodEntry {
private:
    unsigned entryId;
    std::shared_ptr<Food> food;
    double quantityGrams;
    Date date;
public:
    FoodEntry();
    FoodEntry(unsigned entryId, std::shared_ptr<Food> food, double quantityGrams, const Date& date);
    unsigned getEntryId() const;
    std::shared_ptr<Food> getFood() const;
    double getQuantityGrams() const;
    const Date& getDate() const;
    double getCalories() const;
    double getProtein() const;
    double getCarbs() const;
    double getFat() const;
};
