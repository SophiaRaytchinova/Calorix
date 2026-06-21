#include "../../include/models/Food.h"

Food::Food() : foodId(0), caloriesPer100g(0), proteinPer100g(0), carbsPer100g(0), fatPer100g(0) {}

Food::Food(unsigned id, const std::string& n, double c, double p, double carbs, double f) : foodId(id), name(n), caloriesPer100g(c), proteinPer100g(p), carbsPer100g(carbs), fatPer100g(f) {}

unsigned Food::getFoodId() const 
{
    return foodId; 
}

const std::string& Food::getName() const 
{ 
    return name; 
}

double Food::getCaloriesPer100g() const 
{ 
    return caloriesPer100g; 
}

double Food::getProteinPer100g() const 
{ 
    return proteinPer100g; 
}

double Food::getCarbsPer100g() const 
{ 
    return carbsPer100g; 
}

double Food::getFatPer100g() const 
{ 
    return fatPer100g; 
}

void Food::setCalories(double c) 
{ 
    caloriesPer100g = c; 
}
