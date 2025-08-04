#include<bits/stdc++.h>
using namespace std;
// Problem: Fruit Into Baskets
// Approach: Use a sliding window technique to find the maximum number of fruits that can be collected with at most two types of fruits.
// Steps:
// 1. Maintain two variables to track the last two types of fruits and their counts.
// 2. Use a single loop to iterate through the array of fruits.
// 3. If the current fruit is one of the last two types, increment the count.
// 4. If the current fruit is a new type, update the counts accordingly and reset the count for the previous type.
// 5. Keep track of the maximum count of fruits collected during this process.
// Time Complexity: O(n) where n is the number of fruits in the array.
class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int lastFruit = -1, secondLastFruit = -1;
        int lastFruitCount = 0;
        int maxCount = 0, curCount = 0;

        for (int fruit : arr) {
            if (fruit == lastFruit || fruit == secondLastFruit) {
                curCount++;
            } else {
                curCount = lastFruitCount + 1;  // just last streak + new fruit
            }

            if (fruit == lastFruit) lastFruitCount++;
            else {
                lastFruitCount = 1;
                secondLastFruit = lastFruit;
                lastFruit = fruit;
            }

            maxCount = max(maxCount, curCount);
        }
        return maxCount;
    }
};