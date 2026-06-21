#include "../../include/repositories/ExerciseRepository.h"

void ExerciseRepository::clear() 
{
    exercises.clear();
} 

void ExerciseRepository::addExercise(const Exercise& e) 
{ 
    if(exists(e.getName())) return; 
    exercises.push_back(std::make_shared<Exercise>(e)); 
} 

bool ExerciseRepository::exists(const std::string& n) const
{
    return findExercise(n) != nullptr;
} 

std::shared_ptr<Exercise> ExerciseRepository::findExercise(const std::string& n) const
{ 
    for (const auto& e:exercises) 
    {
        if (e->getName() == n) 
        {
            return e;
        }
    }
    
    return nullptr;
} 

const std::vector<std::shared_ptr<Exercise>>& ExerciseRepository::getExercises() const 
{ 
    return exercises;
}