#include <vector>
#include <map>
#include <algorithm>
#include <climits>
// Problem: Rearranging Fruits in Two Baskets
// Approach: Use a map to count occurrences of each fruit in both baskets, then determine the minimum cost to balance them.
// Steps:
// 1. Count the occurrences of each fruit in both baskets.
// 2. Check if the total count of each fruit is even; if not, return -1.
// 3. Calculate the minimum fruit value to determine the cost of swapping.
// 4. Create a list of fruits that need to be swapped based on the difference in counts.
// 5. Sort the list of fruits to swap and calculate the total cost based on the minimum fruit value.
// Time Complexity: O(n log n) due to sorting, where n is the number of unique fruits.


class Solution {
public:
    long long minCost(std::vector<int>& basket1, std::vector<int>& basket2) {
        std::map<int, int> total_counts;
        for (int fruit : basket1) total_counts[fruit]++;
        for (int fruit : basket2) total_counts[fruit]++;

        long long min_val = LLONG_MAX;
        for (auto const& [fruit, count] : total_counts) {
            if (count % 2 != 0) return -1;
            min_val = std::min(min_val, (long long)fruit);
        }
        
        std::vector<long long> fruits_to_swap;
        std::map<int, int> count1;
        for (int fruit : basket1) count1[fruit]++;
        
        for (auto const& [fruit, total_count] : total_counts) {
            int diff = count1[fruit] - (total_count / 2);
            for (int i = 0; i < abs(diff); ++i) {
                fruits_to_swap.push_back(fruit);
            }
        }
        
        std::sort(fruits_to_swap.begin(), fruits_to_swap.end());
        
        long long total_cost = 0;
        int swaps_to_make = fruits_to_swap.size() / 2;
        for (int i = 0; i < swaps_to_make; ++i) {
            total_cost += std::min(fruits_to_swap[i], 2 * min_val);
        }
        
        return total_cost;
    }
};