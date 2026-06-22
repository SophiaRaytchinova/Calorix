#pragma once
#include <vector>
#include <memory>
#include "../models/Exercise.h"

class WorkoutGenerator {
public:
    static std::vector<std::shared_ptr<Exercise>> generatePlan(
        const std::vector<std::shared_ptr<Exercise>>& exercises, 
        int durationMinutes
    );
    static double planCalories(const std::vector<std::shared_ptr<Exercise>>& plan);
};
