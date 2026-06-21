#pragma once
#include <memory>
#include "Exercise.h"
#include "Date.h"

class ExerciseEntry {
private:
    unsigned entryId;
    std::shared_ptr<Exercise> exercise;
    int durationMinutes;
    Date date;
public:
    ExerciseEntry();
    ExerciseEntry(unsigned entryId, std::shared_ptr<Exercise> exercise, int durationMinutes, const Date& date);
    unsigned getEntryId() const;
    std::shared_ptr<Exercise> getExercise() const;
    int getDurationMinutes() const;
    const Date& getDate() const;
    double caloriesBurned() const;
};
