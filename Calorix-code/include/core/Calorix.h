#pragma once
#include <string>
#include "../models/Enums.h"
#include "../repositories/UserRepository.h"
#include "../repositories/FoodRepository.h"
#include "../repositories/ExerciseRepository.h"

class Calorix {
private:
    UserRepository userRepository;
    FoodRepository foodRepository;
    ExerciseRepository exerciseRepository;
    User* currentUser;
    unsigned nextUserId;
    unsigned nextFoodId;
    unsigned nextExerciseId;
    unsigned nextEntryId;
    bool isCurrentUserAdmin() const;
    bool isCurrentUserTrainee() const;
    void seedDefaultDataIfEmpty();
public:
    Calorix();
    void load();
    void save() const;
    void registerUser(const std::string& username, const std::string& password, int age, double weight, double height, Gender gender);
    void setNextUserId(unsigned id);
    void setNextFoodId(unsigned id);
    void setNextExerciseId(unsigned id);
    void setNextEntryId(unsigned id);
    bool login(const std::string& username, const std::string& password);
    void logout();
    bool isLoggedIn() const;
    User* getCurrentUser();
    const User* getCurrentUser() const;
    UserRepository& getUserRepository();
    const UserRepository& getUserRepository() const;
    FoodRepository& getFoodRepository();
    const FoodRepository& getFoodRepository() const;
    ExerciseRepository& getExerciseRepository();
    const ExerciseRepository& getExerciseRepository() const;
    unsigned generateEntryId();
    unsigned generateFoodId();
    unsigned generateExerciseId();
    unsigned generateUserId();
    void executeCommand(const std::string& commandLine);
};
