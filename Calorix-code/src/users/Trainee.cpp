#include "../../include/users/Trainee.h"
#include <iostream>
#include <iomanip>

Trainee::Trainee() : User() {} 

Trainee::Trainee(unsigned id, const std::string& u, const std::string& p, const UserProfile& pr) : User(id, u, p, pr) {}

void Trainee::logFood(const FoodEntry& e)
{
    foodDiary.push_back(e);
} 

void Trainee::logExercise(const ExerciseEntry& e)
{
    exerciseDiary.push_back(e);
} 

void Trainee::addGoal(const FitnessGoal& g)
{
    goals.push_back(g);
} 

void Trainee::addToFavorites(const std::string& ex)
{
    for(const auto& f:favoriteExercises)
        if (f == ex)
        {
            std::cout << "Exercise already in favorites.\n";
            return;
        }
    favoriteExercises.push_back(ex);
}

void Trainee::viewFavorites() const
{
    if (favoriteExercises.empty())
    {
        std::cout << "No favorite exercises.\n";
        return;
    }
    std::cout << "Favorite exercises:\n";
    for (const auto& e:favoriteExercises) 
    {
        std::cout << "- " << e << "\n";
    }       
}

void Trainee::viewDailySummary()const
{
    double cal=0, p=0, c=0, fat=0, out=0;
    for (const auto& x:foodDiary)
        if (x.getDate() == Date::today())
        {
            cal += x.getCalories();
            p += x.getProtein();
            c += x.getCarbs();
            fat += x.getFat();
        }
    for (const auto& x:exerciseDiary)
        if (x.getDate() == Date::today())
            out += x.caloriesBurned();
    std::cout << std::fixed << std::setprecision(2) << "Daily summary (" << Date::today().toString() << "):\nCalories in: " << cal << " kcal\nProtein: " << p << " g\nCarbs: " << c << " g\nFat: " << fat << " g\nCalories burned: " << out << " kcal\nNet balance: " << (cal - out) << " kcal\n";
}

void Trainee::viewProgress()const
{
    if (goals.empty())
    {
        std::cout<<"No goals set.\n";
        return;
    }
    const auto& g = goals.back();
    std::cout << "Current goal: " << toString(g.getGoalType()) << "\nTarget value: " << g.getTargetValue() << "\nStart date: " << g.getStartDate().toString() << "\nDeadline: " << g.getDeadline().toString() << "\nAchieved: " << (g.isAchieved() ? "yes" : "no") << "\n";
    if (g.getGoalType() == GoalType::WEIGHT_LOSS || g.getGoalType() == GoalType::BULKING)
    {
        double diff = g.getTargetValue() - profile.getWeight();
        if (diff > 0)
            std::cout << "Remaining gain: " << diff << " kg\n";
        else if (diff < 0)
            std::cout << "Remaining loss: " << -diff << " kg\n";
        else
            std::cout << "Target weight reached.\n";
    }
}
double Trainee::calculateBMI() const
{
    return profile.calculateBMI();
} 

double Trainee::calculateBMR() const
{
    return profile.calculateBMR();
}

const std::vector<FoodEntry>& Trainee::getFoodDiary() const
{
    return foodDiary;
} 

const std::vector<ExerciseEntry>& Trainee::getExerciseDiary() const
{
    return exerciseDiary;
}

const std::vector<FitnessGoal>& Trainee::getGoals() const
{
    return goals;
}

const std::vector<std::string>& Trainee::getFavorites() const
{
    return favoriteExercises;
}

void Trainee::help() const
{
    std::cout << "Trainee commands:\nset-goals <goal-type> <target-value> <deadline YYYY-MM-DD>\nlog-food <food-name> <quantity_grams>\nlog-exercise <exercise-name> <duration_minutes>\nview-daily-summary\nview-progress\ncalculate-bmi\ncalculate-bmr\ngenerate-workout-plan <duration_minutes>\nadd-to-favorites <exercise-name>\nview-favorites\nlogout\nhelp\nend\n";
}

std::string Trainee::getType() const
{
    return "Trainee";
}
