#pragma once
#include <string>

class Food {
private:
    unsigned foodId;
    std::string name;
    double caloriesPer100g;
    double proteinPer100g;
    double carbsPer100g;
    double fatPer100g;
public:
    Food();
    Food(unsigned foodId, const std::string& name, double calories, double protein, double carbs, double fat);
    unsigned getFoodId() const;
    const std::string& getName() const;
    double getCaloriesPer100g() const;
    double getProteinPer100g() const;
    double getCarbsPer100g() const;
    double getFatPer100g() const;
    void setCalories(double calories);
};
