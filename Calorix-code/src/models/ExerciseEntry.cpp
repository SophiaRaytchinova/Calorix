#include "../../include/models/ExerciseEntry.h"

ExerciseEntry::ExerciseEntry() : entryId(0), durationMinutes(0) {}

ExerciseEntry::ExerciseEntry(unsigned id, std::shared_ptr<Exercise> e, int d, const Date& date) : entryId(id), exercise(std::move(e)), durationMinutes(d), date(date) {}

unsigned ExerciseEntry::getEntryId() const
{
    return entryId;
}

std::shared_ptr<Exercise> ExerciseEntry::getExercise() const
{
    return exercise;
}

int ExerciseEntry::getDurationMinutes() const
{
    return durationMinutes;
}

const Date& ExerciseEntry::getDate() const
{
    return date;
}

double ExerciseEntry::caloriesBurned() const
{
    return exercise ? exercise->getCaloriesBurnedPerHour() * durationMinutes / 60.0 : 0;
}
