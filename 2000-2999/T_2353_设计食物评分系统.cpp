#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
using namespace std;



class FoodRatings {
    unordered_map<string, pair<int, string>> foodMap;
    unordered_map<string, set<pair<int, string>>> ratingMap;
    int n;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        n = foods.size();
        for (int i = 0; i < n; ++i) {
            auto &food = foods[i], &cuisine = cuisines[i];
            int rating = ratings[i];
            foodMap[food] = {rating, cuisine};
            ratingMap[cuisine].emplace(n - rating, food);
        }
    }

    void changeRating(string food, int newRating) {
        auto& [rating, cuisine] = foodMap[food];
        auto& s = ratingMap[cuisine];
        s.erase({n - rating, food});
        s.emplace(n - newRating, food);
        rating = newRating;
    }

    string highestRated(string cuisine) { 
        return ratingMap[cuisine].begin()->second; 
    }
};

