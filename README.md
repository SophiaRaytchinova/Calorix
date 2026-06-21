# Calorix Fitness System

Calorix is a C++ console application for tracking food intake, exercise activity, calorie balance, fitness goals and workout planning. The system supports two types of users: regular trainees and administrators.

The project was developed as an Object-Oriented Programming course project for FMI, Sofia University.

## Features

### General user functionality

* Register a new trainee account
* Login and logout
* View available commands depending on the current user role
* Save system data on exit

### Trainee functionality

* Set fitness goals:

  * `WEIGHT_LOSS`
  * `BULKING`
  * `MAINTENANCE`
* Log consumed food
* Log completed exercises
* View daily calorie and macronutrient summary
* View progress toward current fitness goals
* Calculate BMI
* Calculate BMR using the Mifflin-St Jeor formula
* Generate an optimal workout plan
* Add exercises to favorites
* View favorite exercises

### Admin functionality

* Add new foods to the food database
* Add new exercises to the exercise database
* Update food calories
* Block/delete users

## Design

The project follows an object-oriented structure with separate classes for users, profiles, foods, exercises, repositories, entries and system control.

Main OOP concepts used:

* Inheritance
* Polymorphism
* Encapsulation
* Abstraction
* Dynamic dispatch through virtual functions
* Separation of responsibilities

Main design ideas:

* `User` is an abstract base class.
* `Admin` and `Trainee` inherit from `User`.
* Repository classes manage collections of users, foods and exercises.
* `Calorix` is the central system class that manages commands, users and data.
* `UserFactory` is used for creating user objects.
* `WorkoutGenerator` contains the workout plan generation logic.

## Project Structure

```text
Calorix-code/
│
├── include/
│   ├── core/
│   ├── models/
│   ├── repositories/
│   ├── users/
│   └── utils/
│
├── src/
│   ├── core/
│   ├── models/
│   ├── repositories/
│   ├── users/
│   └── utils/
│
├── README.md
```

## Build and Run

### Build with g++

From the root project folder:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic src/main.cpp src/core/*.cpp src/models/*.cpp src/repositories/*.cpp src/users/*.cpp src/utils/*.cpp -o calorix.exe
```

### Run

```bash
./calorix
```

## Default Admin

The system creates a default administrator account:

```text
username: admin
password: admin
```

## Example Commands

### Start the program

```text
help
```

### Register and login as a trainee

```text
register person1 1234 15 70 150 MALE
login person1 1234
help
```

### Login as admin and add data

```text
logout
login admin admin
add-food banana 89 1.1 23 0.3
add-food chicken 165 31 0 3.6
add-exercise running 600 CARDIO 30
add-exercise pushups 350 CHEST 20
logout
```

### Use trainee functionality

```text
login person1 1234
log-food banana 200
log-food chicken 150
log-exercise running 30
view-daily-summary
calculate-bmi
calculate-bmr
set-goals WEIGHT_LOSS 65 2026-07-01
view-progress
add-to-favorites running
view-favorites
generate-workout-plan 45
end
```

## Supported Values

### Gender

```text
MALE
FEMALE
```

### Activity Levels

```text
SEDENTARY
LIGHT
MODERATE
ACTIVE
VERY_ACTIVE
```

### Goal Types

```text
WEIGHT_LOSS
BULKING
MAINTENANCE
```

### Muscle Groups

```text
CHEST
BACK
LEGS
SHOULDERS
ARMS
CORE
CARDIO
```

## Data Persistence

The system stores data in:

```text
calorix_data.txt
```

When the user enters:

```text
end
```

the current state of the system is saved to the file.

The file contains users, foods, exercises, diary entries, goals, favorites and next available object IDs.

## Workout Plan Generation

The workout plan is generated using a 0/1 knapsack-style approach. Each exercise has:

* duration as weight
* burned calories as value

The goal is to maximize burned calories without exceeding the selected duration.

## Notes

Commands must be entered on one line.

Correct:

```text
register person1 1234 15 70 150 MALE
```

Incorrect:

```text
register
person1 1234 15 70 150 MALE
```

## Design Patterns Used

### Factory Method / Simple Factory

The project uses a factory-style class called `UserFactory`.

Locations:

```text
include/users/UserFactory.h
src/users/UserFactory.cpp
```

Reponsible for:

```text
Creating different types of users - admin, trainee
```

### Repository Pattern

The project uses repository classes to manage collections of objects.

Locations:

```text
include/repositories/UserRepository.h
src/repositories/UserRepository.cpp
include/repositories/FoodRepository.h
src/repositories/FoodRepository.cpp
include/repositories/ExerciseRepository.h
src/repositories/ExerciseRepository.cpp
```

Reponsible for:

```text
Storing, searching, adding, updating and removing objects. This separates data management from the business logic in Calorix.
```

