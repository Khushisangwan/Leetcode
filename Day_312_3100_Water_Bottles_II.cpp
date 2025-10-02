#include <bits/stdc++.h>
using namespace std;
/**
 * @brief Calculates the maximum number of bottles that can be drunk given an initial number of bottles
 *        and an exchange mechanism where empty bottles can be traded for new full bottles.
 * 
 * This function simulates a bottle exchange system where:
 * - You start with 'numBottles' full bottles
 * - You can exchange 'x' empty bottles for 1 new full bottle
 * - After each exchange, the required number of empty bottles increases by 1
 * - The process continues until you don't have enough empty bottles for another exchange
 * 
 * @param numBottles The initial number of full bottles available to drink
 * @param x The initial number of empty bottles required to exchange for 1 new full bottle
 * 
 * @return The maximum total number of bottles that can be drunk
 * 
 * Algorithm:
 * 1. Start with ans = numBottles (drink all initial bottles)
 * 2. While we have enough empty bottles (numBottles >= x):
 *    - Exchange x empty bottles for 1 new bottle (numBottles -= x - 1)
 *    - Increment the exchange rate (x++)
 *    - Increment the total bottles drunk (ans++)
 * 3. Return the total count
 * 
 * Time Complexity: O(sqrt(numBottles)) - the exchange rate increases linearly
 * Space Complexity: O(1) - only using constant extra space
 */
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int x) {
        int ans = numBottles;
        while (numBottles >= x) {
            numBottles -= x - 1, x++, ans++;
        }
        return ans;
    }
};