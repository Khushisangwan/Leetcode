#include <bits/stdc++.h>
using namespace std;

class FoodRatings {
    // Custom comparator struct for sorting foods (not used in current implementation)
    struct Compare {
        unordered_map<string, int>* ratingMap;
        Compare(unordered_map<string, int>* rm) : ratingMap(rm) {}
        bool operator()(const string& a, const string& b) const {
            int r1 = ratingMap->at(a);
            int r2 = ratingMap->at(b);
            if (r1 != r2) return r1 > r2;  // higher rating first
            return a < b;                  // lexicographically smaller first
        }
    };

    // Map food name to its cuisine type
    unordered_map<string, string> foodToCuisine;
    // Map food name to its current rating
    unordered_map<string, int> foodToRating;
    // Map cuisine to ordered set of foods (sorted by rating desc, then name asc)
    unordered_map<string, set<string, function<bool(const string&, const string&)>>> cuisineFoods;

public:
    // Constructor: Initialize the food rating system
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        // Build food to cuisine and food to rating mappings
        for (int i = 0; i < foods.size(); i++) {
            foodToCuisine[foods[i]] = cuisines[i];
            foodToRating[foods[i]] = ratings[i];
        }

        // Group foods by cuisine with custom ordering
        for (int i = 0; i < foods.size(); i++) {
            string cuisine = cuisines[i];
            // Create new set for cuisine if it doesn't exist
            if (!cuisineFoods.count(cuisine)) {
                cuisineFoods[cuisine] = set<string, function<bool(const string&, const string&)>>(
                    [&](const string& a, const string& b) {
                        int r1 = foodToRating[a];
                        int r2 = foodToRating[b];
                        if (r1 != r2) return r1 > r2;  // Higher rating first
                        return a < b;                  // Lexicographically smaller first if ratings equal
                    }
                );
            }
            // Add food to the cuisine's ordered set
            cuisineFoods[cuisine].insert(foods[i]);
        }
    }

    // Update a food's rating and maintain ordering in cuisine set
    void changeRating(string food, int newRating) {
        string cuisine = foodToCuisine[food];
        auto& s = cuisineFoods[cuisine];

        // Remove food from set (with old rating)
        s.erase(food);
        // Update the rating
        foodToRating[food] = newRating;
        // Re-insert food with new rating (will be in correct position)
        s.insert(food);
    }

    // Get the highest rated food for a given cuisine
    string highestRated(string cuisine) {
        // Return first element (highest rated) from the ordered set
        return *cuisineFoods[cuisine].begin();
    }
};