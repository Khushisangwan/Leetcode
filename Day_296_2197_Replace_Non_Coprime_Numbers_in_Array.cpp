#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> stack;
        
        // Process each number in the input array
        for (int num : nums) {
            // Keep merging with stack top while they're not coprime
            while (!stack.empty()) {
                int top = stack.back();
                int g = gcd(top, num);
                
                // If GCD is 1, numbers are coprime - stop merging
                if (g == 1) {
                    break;
                }
                
                // Remove top element and merge it with current number
                stack.pop_back();
                
                // Compute LCM using formula: LCM(a,b) = (a*b)/GCD(a,b)
                // Use long long to avoid overflow during multiplication
                long long merged = (long long)top / g * num;
                num = (int)merged;
            }
            
            // Add the (possibly merged) number to stack
            stack.push_back(num);
        }
        
        return stack;
    }
    
private:
    // Helper function to compute Greatest Common Divisor using Euclidean algorithm
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};