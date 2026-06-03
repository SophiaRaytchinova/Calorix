#pragma once
#include <string>

class Food {
protected:
    static int nextFoodId;
    int foodId;
    std::string name;
    int caloriesPer100g;
    double proteinPer100g;
    double carbPer100g;
    double fatPer100g;
public: 
    Food(const std::string& name_, int caloriesPer100g_, double proteinPer100g_, double carbPer100g_, double fatPer100g_);
    std::string getName() const;
    int getCaloriesPer100g() const;
    double getProteinPer100g() const;
    double getCarbPer100g() const;
    double getFatPer100g() const;
    virtual ~Food() = default;
};