#include "../../include/utils/WorkoutGenerator.h"
#include <vector>
#include <algorithm>
//dynamic programming table to fix 0/1 knapsack problem
//най-много калории, които могат да се изгорят за дадено време, като се използват наличните упражнения

std::vector<std::shared_ptr<Exercise>> WorkoutGenerator::generatePlan(const std::vector<std::shared_ptr<Exercise>>& exercises,int durationMinutes) {
    if (durationMinutes <= 0) return {}; 

    struct Item {
        std::shared_ptr<Exercise> ex; 
        int time; 
        double val;
    }; 

    std::vector<Item> items; 
    for(auto& ex:exercises) {
        int t = std::max(1, ex->getRecommendedDurationMinutes()); 
        items.push_back({ex, t, ex->getCaloriesBurnedPerHour() * t / 60.0}); 
    } 

    int n = (int) items.size(); 
    std::vector<std::vector<double>> dp(n + 1, std::vector<double>(durationMinutes + 1)); 
    for (int i = 1; i <= n; i++) 
    {
        for (int t = 0; t <= durationMinutes; t++)
        {
            dp[i][t] = dp[i - 1][t];
            if(items[i - 1].time <= t) 
            {
                dp[i][t] = std::max(dp[i][t], dp[i - 1][t - items[i - 1].time] + items[i - 1].val);
            }
        }
    }
    
    std::vector<std::shared_ptr<Exercise>> res; 
    int t = durationMinutes; 
    for (int i = n; i > 0; i--) 
    {
        if (dp[i][t] > dp[i - 1][t] + 1e-9)
        {
            res.push_back(items[i - 1].ex); 
            t -= items[i - 1].time; 
        }
    }
    std::reverse(res.begin(), res.end()); 
    return res; 
}
double WorkoutGenerator::planCalories(const std::vector<std::shared_ptr<Exercise>>& plan) {
    double s = 0; 
    for(const auto& e:plan) 
    {
        s += e->getCaloriesBurnedPerHour() * e->getRecommendedDurationMinutes() / 60.0; 
    }
    return s; 
}
