#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        // Try operations from 1 to 60 (enough for 64-bit integers)
        for(int i=1;i<=60;i++){
            // Calculate what remains after i operations: num1 - i*num2
            long long remaining=num1-1LL * i*num2;
            
            // If remaining is less than i, impossible to achieve zero
            // (need at least i positive powers of 2)
            if(remaining<i) continue;

            // Count number of 1-bits in remaining (minimum powers of 2 needed)
            int ones=0;
            long long temp=remaining;
            while(temp>0){
                ones+=(temp & 1);  // Check if LSB is 1
                temp>>=1;          // Right shift to check next bit
            }
            
            // If we can represent remaining as sum of exactly i powers of 2
            // (ones <= i because we can split powers into smaller ones)
            if(ones<=i) return i;
        }
        // No solution found
        return -1;
    }
};