#pragma once
#include <vector>
#include <memory>
#include <string>
#include "../models/Exercise.h"

class ExerciseRepository {
private:
    std::vector<std::shared_ptr<Exercise>> exercises;
public:
    void clear();
    void addExercise(const Exercise& exercise);
    bool exists(const std::string& name) const;
    std::shared_ptr<Exercise> findExercise(const std::string& name) const;
    const std::vector<std::shared_ptr<Exercise>>& getExercises() const;
};
