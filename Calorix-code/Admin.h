#include "User.h"
#include "Enums.h"

class Admin : public User {
public:
    void blockUser(std::string username);
    void addFood(std::string foodName, int caloriesPer100g, double proteinPer100g, double carbPer100g, double fatPer100g);
    void addExercise(std::string exerciseName, double caloriesBurnedPerMinute, muscleGroup muscleGroup);
    void updateFood(std::string foodName, int caloriesPer100g, double proteinPer100g, double carbPer100g, double fatPer100g);
};