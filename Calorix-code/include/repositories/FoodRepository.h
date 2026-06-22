#pragma once
#include <vector>
#include <memory>
#include <string>
#include "../models/Food.h"

class FoodRepository {
private:
    std::vector<std::shared_ptr<Food>> foods;
public:
    void clear();
    void addFood(const Food& food);
    bool exists(const std::string& name) const;
    std::shared_ptr<Food> findFood(const std::string& name) const; //връща shared защото и foodEntry трябва са сочи към същия пойнтър
    void updateFoodCalories(const std::string& name, double newCalories);
    const std::vector<std::shared_ptr<Food>>& getFoods() const;
};
