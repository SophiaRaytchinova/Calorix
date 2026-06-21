#include "../../include/core/Calorix.h"
#include "../../include/core/CommandParser.h"
#include "../../include/users/UserFactory.h"
#include "../../include/utils/WorkoutGenerator.h"
#include "../../include/users/Admin.h"
#include "../../include/users/Trainee.h"
#include "../../include/repositories/UserRepository.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stdexcept>

static const char* DATA_FILE = "calorix_data.txt";

static std::vector<std::string> splitLine(const std::string& line, char delimiter='|') 
{
    std::vector<std::string> result;
    std::stringstream ss(line);
    std::string part;
    while (std::getline(ss, part, delimiter)) result.push_back(part);
    return result;
}

Calorix::Calorix() : currentUser(nullptr), nextUserId(1), nextFoodId(1), nextExerciseId(1), nextEntryId(1) {}

void Calorix::setNextUserId(unsigned id)
{
    nextUserId=id;
} 

void Calorix::setNextFoodId(unsigned id)
{
    nextFoodId=id;
} 

void Calorix::setNextExerciseId(unsigned id) 
{
    nextExerciseId=id;
} 

void Calorix::setNextEntryId(unsigned id)
{
    nextEntryId=id;
}
unsigned Calorix::generateUserId()
{
    return nextUserId++;
} 

unsigned Calorix::generateFoodId()
{
    return nextFoodId++;
} 

unsigned Calorix::generateExerciseId()
{
    return nextExerciseId++;
} 

unsigned Calorix::generateEntryId()
{
    return nextEntryId++;
}

UserRepository& Calorix::getUserRepository()
{
    return userRepository;
} 

const UserRepository& Calorix::getUserRepository() const
{
    return userRepository;
} 

FoodRepository& Calorix::getFoodRepository()
{
    return foodRepository;
} 

const FoodRepository& Calorix::getFoodRepository() const
{
    return foodRepository;
} 

ExerciseRepository& Calorix::getExerciseRepository()
{
    return exerciseRepository;
} 

const ExerciseRepository& Calorix::getExerciseRepository() const
{
    return exerciseRepository;
} 

bool Calorix::isLoggedIn() const
{
    return currentUser != nullptr;
}

User* Calorix::getCurrentUser()
{
    return currentUser;
} 

const User* Calorix::getCurrentUser() const
{
    return currentUser;
}

bool Calorix::isCurrentUserAdmin() const
{
    return currentUser && currentUser->getType() == "Admin";
}

bool Calorix::isCurrentUserTrainee() const
{
    return currentUser && currentUser->getType() == "Trainee";
}

void Calorix::seedDefaultDataIfEmpty()
{
    if (!userRepository.usernameExists("admin")) 
    {
        UserProfile p(30, 75, 175, Gender::MALE, ActivityLevel::MODERATE);
        userRepository.addUser(UserFactory::createAdmin(generateUserId(), "admin", "admin", p));
    }
    if (foodRepository.getFoods().empty()){
        foodRepository.addFood(Food(generateFoodId(), "apple", 52, 0.3, 14, 0.2));
        foodRepository.addFood(Food(generateFoodId(), "chicken", 165, 31, 0, 3.6));
        foodRepository.addFood(Food(generateFoodId(), "rice", 130, 2.7, 28, 0.3));
    }
    if (exerciseRepository.getExercises().empty()){
        exerciseRepository.addExercise(Exercise(generateExerciseId(), "running", 600, MuscleGroup::CARDIO, 30));
        exerciseRepository.addExercise(Exercise(generateExerciseId(), "squats", 420, MuscleGroup::LEGS, 25));
        exerciseRepository.addExercise(Exercise(generateExerciseId(), "pushups", 350, MuscleGroup::CHEST, 20));
        exerciseRepository.addExercise(Exercise(generateExerciseId(), "plank", 220, MuscleGroup::CORE, 10));
    }
}

void Calorix::load()
{
    userRepository.clear(); 
    foodRepository.clear(); 
    exerciseRepository.clear(); 
    currentUser=nullptr;

    std::ifstream in(DATA_FILE);
    if (!in)
    { 
        seedDefaultDataIfEmpty(); 
        return; 
    }
    std::string line;
    while (std::getline(in,line))
    {
        if(line.empty() || line[0]=='#') continue;
        auto p = splitLine(line);
        try {
            if (p[0] == "NEXT" && p.size() >= 5)
            { 
                nextUserId = std::stoul(p[1]); 
                nextFoodId = std::stoul(p[2]); 
                nextExerciseId = std::stoul(p[3]); 
                nextEntryId = std::stoul(p[4]); 
            }
            else if (p[0] == "FOOD" && p.size() >= 7)
            { 
                foodRepository.addFood(Food(std::stoul(p[1]), p[2], std::stod(p[3]), std::stod(p[4]), std::stod(p[5]), std::stod(p[6]))); 
            }
            else if (p[0] == "EXERCISE" && p.size() >= 7)
            { 
                exerciseRepository.addExercise(Exercise(std::stoul(p[1]), p[2], std::stod(p[3]), muscleGroupFromString(p[4]), std::stoi(p[5]))); 
            }
            else if (p[0] == "USER" && p.size() >= 10)
            { 
                UserProfile prof(std::stoi(p[5]), std::stod(p[6]), std::stod(p[7]), genderFromString(p[8]), activityLevelFromString(p[9])); 
                if (p[1] == "Admin") 
                    userRepository.addUser(UserFactory::createAdmin(std::stoul(p[2]), p[3], p[4], prof)); 
                else userRepository.addUser(UserFactory::createTrainee(std::stoul(p[2]), p[3], p[4], prof)); 
            }
            else if (p[0] == "GOAL" && p.size() >= 7)
            { 
                auto* u = dynamic_cast<Trainee*>(userRepository.findByUsername(p[1])); 
                if (u) u->addGoal(FitnessGoal(goalTypeFromString(p[2]), std::stod(p[3]), Date::fromString(p[4]), Date::fromString(p[5]), p[6] == "1")); 
            }
            else if (p[0] == "FAVORITE" && p.size() >= 3)
            { 
                auto* u = dynamic_cast<Trainee*>(userRepository.findByUsername(p[1])); 
                if (u) u->addToFavorites(p[2]); 
            }
            else if (p[0] == "FOODENTRY" && p.size() >= 6)
            { 
                auto* u = dynamic_cast<Trainee*>(userRepository.findByUsername(p[1])); 
                auto f = foodRepository.findFood(p[3]); 
                if (u && f) u->logFood(FoodEntry(std::stoul(p[2]), f, std::stod(p[4]), Date::fromString(p[5]))); 
            }
            else if (p[0] == "EXERCISEENTRY" && p.size() >= 6)
            { 
                auto* u = dynamic_cast<Trainee*>(userRepository.findByUsername(p[1])); 
                auto e = exerciseRepository.findExercise(p[3]); 
                if (u && e) u->logExercise(ExerciseEntry(std::stoul(p[2]), e, std::stoi(p[4]), Date::fromString(p[5]))); 
            }
        } catch(...) {}
    }
    seedDefaultDataIfEmpty();
}

void Calorix::save() const
{
    std::ofstream out(DATA_FILE);
    out << "NEXT|" << nextUserId << '|' << nextFoodId << '|' << nextExerciseId << '|' << nextEntryId << "\n";
    for (const auto& f: foodRepository.getFoods()) 
    {
        out << "FOOD|" << f->getFoodId() << '|' << f->getName() << '|' << f->getCaloriesPer100g() << '|' << f->getProteinPer100g() << '|' << f->getCarbsPer100g() << '|' << f->getFatPer100g() << "\n";
    }
    for (const auto& e: exerciseRepository.getExercises()) 
    {
        out << "EXERCISE|" << e->getExerciseId() << '|' << e->getName() << '|' << e->getCaloriesBurnedPerHour() << '|' << toString(e->getMuscleGroup()) << '|' << e->getRecommendedDurationMinutes() << "|0\n";
    }
    for (const auto& u: userRepository.getUsers())
    {
        const auto& pr = u->getProfile();
        out << "USER|" << u->getType() << '|' << u->getUserId() << '|' << u->getUsername() << '|' << u->getPassword() << '|' << pr.getAge() << '|' << pr.getWeight() << '|' << pr.getHeight() << '|' << toString(pr.getGender()) << '|' << toString(pr.getActivityLevel()) << "\n";
        if (auto t=dynamic_cast<const Trainee*>(u.get()))
        {
            for (const auto& g:t->getGoals()) 
            {
                out << "GOAL|" << u->getUsername() << '|' << toString(g.getGoalType()) << '|' << g.getTargetValue() << '|' << g.getStartDate().toString() << '|' << g.getDeadline().toString() << '|' << (g.isAchieved() ? 1 : 0) << "\n";
            }
                for (const auto& f:t->getFavorites()) 
            {
                out << "FAVORITE|" << u->getUsername() << '|' << f << "\n";
            }
            for (const auto& fe:t->getFoodDiary()) 
            {
                if (fe.getFood()) 
                {
                    out << "FOODENTRY|" << u->getUsername() << '|' << fe.getEntryId() << '|' << fe.getFood()->getName() << '|' << fe.getQuantityGrams() << '|' << fe.getDate().toString() << "\n";
                }
            }
            for (const auto& ee:t->getExerciseDiary()) 
            {
                if (ee.getExercise()) 
                {
                    out << "EXERCISEENTRY|" << u->getUsername() << '|' << ee.getEntryId() << '|' << ee.getExercise()->getName() << '|' << ee.getDurationMinutes() << '|' << ee.getDate().toString() << "\n";
                }
            }
        }
    }
}

void Calorix::registerUser(const std::string& username, const std::string& password, int age, double weight, double height, Gender gender)
{
    if (userRepository.usernameExists(username))
    {
        std::cout << "Username already exists.\n"; 
        return;
    }
    if (age <= 0 || weight <= 0 || height <= 0)
    {
        std::cout << "Invalid profile data.\n"; return;
    }

    UserProfile profile(age, weight, height, gender, ActivityLevel::MODERATE);
    userRepository.addUser(UserFactory::createTrainee(generateUserId(), username, password, profile));
    std::cout << "User registered successfully.\n";
}

bool Calorix::login(const std::string& username, const std::string& password)
{ 
    User* u = userRepository.findByUsername(username); 
    if (!u)
    {
        std::cout << "User not found.\n";
        return false;
    }

    if (!u->checkPassword(password))
    {
        std::cout << "Wrong password.\n";
        return false;
    }
    currentUser = u;
    std::cout << "Logged in as " << u->getUsername() << " (" << u->getType() << ").\n";
    return true;
}

void Calorix::logout()
{
    if (!currentUser)
    {
        std::cout << "No user is logged in.\n";
        return;
    }
    currentUser = nullptr;
    std::cout << "Logged out.\n";
}

void Calorix::executeCommand(const std::string& commandLine)
{
    auto tokens = CommandParser::split(commandLine); 
    if (tokens.empty()) return; 
    const auto& cmd = tokens[0];
    try {
    if (cmd == "register")
    {
        if (tokens.size() != 7)
        {
            std::cout << "Usage: register <username> <password> <age> <weight> <height> <gender>\n";
            return;
        } 
        registerUser(tokens[1], tokens[2], std::stoi(tokens[3]), std::stod(tokens[4]), std::stod(tokens[5]), genderFromString(tokens[6]));
    } 
    else if (cmd == "login")
    {
        if (tokens.size() != 3)
        {
            std::cout << "Usage: login <username> <password>\n";
            return;
        }
        login(tokens[1], tokens[2]);
    } 
    else if (cmd == "logout")
    {
        logout();
    }
    else if (cmd == "help")
    {
        if (currentUser)
        {
            currentUser->help();
        }
        else
        {
            std::cout << "General commands:\nregister <username> <password> <age> <weight> <height> <gender>\nlogin <username> <password>\nhelp\nend\nDefault admin: admin admin\n";
        }
    }
    else if (cmd == "add-food")
    {
        if (!isCurrentUserAdmin())
        {
            std::cout << "Only admin can add food.\n";
            return;
        } 
        if (tokens.size() != 6)
        {
            std::cout << "Usage: add-food <name> <calories> <protein> <carbs> <fat>\n";
            return;
        }
        if (foodRepository.exists(tokens[1]))
        {
            std::cout << "Food already exists.\n";
            return;
        }
        foodRepository.addFood(Food(generateFoodId(), tokens[1], std::stod(tokens[2]), std::stod(tokens[3]), std::stod(tokens[4]), std::stod(tokens[5])));
        std::cout << "Food added.\n";
    }
    else if (cmd == "update-food")
    {
        if (!isCurrentUserAdmin())
        {
            std::cout << "Only admin can update food.\n";
            return;
        }
        if (tokens.size() != 3)
        {
            std::cout << "Usage: update-food <food-name> <new-calories>\n";
            return;
        }
        if (!foodRepository.exists(tokens[1]))
        {
            std::cout << "Food not found.\n";
            return;
        }
        foodRepository.updateFoodCalories(tokens[1], std::stod(tokens[2]));
        std::cout << "Food updated.\n";
    }
    else if (cmd == "block-user")
    {
        if (!isCurrentUserAdmin())
        {
            std::cout << "Only admin can block users.\n";
            return;
        }
        if (tokens.size() != 2)
        {
            std::cout << "Usage: block-user <username>\n";
            return;
        }
        if (tokens[1] == currentUser->getUsername())
        {
            std::cout << "Admin cannot block itself while logged in.\n";
            return;
        }
        if (!userRepository.usernameExists(tokens[1]))
        {
            std::cout << "User not found.\n";
            return;
        }
        userRepository.removeUser(tokens[1]);
        std::cout << "User blocked/deleted.\n";
    } 
    else if(cmd=="log-food")
    {
        if (!isCurrentUserTrainee())
        {
            std::cout << "Login as trainee first.\n";
            return;
        }
        if (tokens.size() != 3)
        {
            std::cout << "Usage: log-food <food-name> <quantity_grams>\n";
            return;
        }
        auto food = foodRepository.findFood(tokens[1]);
        if (!food)
        {
            std::cout << "Food not found.\n";
            return;
        }
        currentUser->logFood(FoodEntry(generateEntryId(), food, std::stod(tokens[2]), Date::today()));
        std::cout << "Food logged.\n";
    }
    else if (cmd == "log-exercise")
    {
        if (!isCurrentUserTrainee())
        {
            std::cout << "Login as trainee first.\n";
            return;
        }
        if (tokens.size() != 3)
        {
            std::cout << "Usage: log-exercise <exercise-name> <duration_minutes>\n";
            return;
        }
        auto ex = exerciseRepository.findExercise(tokens[1]);
        if (!ex)
        {
            std::cout << "Exercise not found.\n";
            return;
        }
        currentUser->logExercise(ExerciseEntry(generateEntryId(), ex, std::stoi(tokens[2]), Date::today()));
        std::cout << "Exercise logged.\n";
    }
    else if (cmd == "view-daily-summary" || cmd == "view-summary")
    {
        if (!isCurrentUserTrainee())
        {
            std::cout << "Login as trainee first.\n";
            return;
        }
        currentUser->viewDailySummary();
    }
    else if (cmd == "set-goals" || cmd == "set-goal")
    {
        if (!isCurrentUserTrainee())
        {
            std::cout << "Login as trainee first.\n";
            return;
        }
        if (tokens.size() != 4)
        {
            std::cout << "Usage: set-goals <goal-type> <target-value> <deadline YYYY-MM-DD>\n";
            return;
        }
        auto* t = dynamic_cast<Trainee*>(currentUser);
        t->addGoal(FitnessGoal(goalTypeFromString(tokens[1]), std::stod(tokens[2]), Date::today(), Date::fromString(tokens[3])));
        std::cout << "Goal set.\n";
    }
    else if (cmd == "view-progress")
    {
        if (!isCurrentUserTrainee())
        {
            std::cout << "Login as trainee first.\n";
            return;
        }
        currentUser->viewProgress();
    }
    else if (cmd == "calculate-bmi")
    {
        if (!isCurrentUserTrainee())
        {
            std::cout << "Login as trainee first.\n";
            return;
        }
        auto* t = dynamic_cast<Trainee*>(currentUser);
        std::cout << std::fixed << std::setprecision(2) << "BMI: " << t->calculateBMI() << "\n";
    }
    else if (cmd == "calculate-bmr")
    {
        if (!isCurrentUserTrainee())
        {
            std::cout << "Login as trainee first.\n";
            return;
        }
        auto* t = dynamic_cast<Trainee*>(currentUser);
        std::cout << std::fixed << std::setprecision(2) << "BMR: " << t->calculateBMR() << " kcal/day\nEstimated daily calories: " << t->getProfile().calculateDailyCalories() << " kcal/day\n";
    }
    else if (cmd == "add-to-favorites")
    {
        if (!isCurrentUserTrainee())
        {
            std::cout << "Login as trainee first.\n";
            return;
        }
        if (tokens.size() != 2)
        {
            std::cout << "Usage: add-to-favorites <exercise-name>\n";
            return;
        }
        if (!exerciseRepository.exists(tokens[1]))
        {
            std::cout << "Exercise not found.\n";
            return;
        }
        dynamic_cast<Trainee*>(currentUser)->addToFavorites(tokens[1]);
        std::cout << "Favorite saved.\n";
    }
    else if (cmd == "view-favorites")
    {
        if (!isCurrentUserTrainee())
        {
            std::cout << "Login as trainee first.\n";
            return;
        }
        dynamic_cast<Trainee*>(currentUser)->viewFavorites();
    } 
    else if (cmd == "generate-workout-plan")
    {
        if (!isCurrentUserTrainee())
        {
            std::cout << "Login as trainee first.\n";
            return;
        } 
        if (tokens.size() != 2)
        {
            std::cout << "Usage: generate-workout-plan <duration_minutes>\n";
            return;
        } 
        int duration = std::stoi(tokens[1]); 
        auto plan = WorkoutGenerator::generatePlan(exerciseRepository.getExercises(), duration); 
        if (plan.empty())
        {
            std::cout << "No workout plan can be generated.\n";
            return;
        } 
        int totalTime = 0; 
        std::cout << "Workout plan:\n"; 

        for(const auto& e:plan)
        { 
            totalTime += e->getRecommendedDurationMinutes(); 
            std::cout << "- " << e->getName() << " (" << e->getRecommendedDurationMinutes() << " min, " << toString(e->getMuscleGroup()) << ")\n"; 
        } std::cout<<std::fixed<<std::setprecision(2)<<"Total time: "<<totalTime<<" min\nExpected calories burned: "<<WorkoutGenerator::planCalories(plan)<<" kcal\n";
    } 
    else std::cout<<"Unknown command. Type help.\n";
    } 
    catch (const std::exception& e)
    {
        std::cout<<"Error: "<<e.what()<<"\n"; 
    }
}
