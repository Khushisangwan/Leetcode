#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        // Check each element against the next 1 or 2 elements
        // The repeated element must appear within this distance
        for (int i = 0; i < A.size() - 2; ++i)
            if (A[i] == A[i + 1] || A[i] == A[i + 2])
                return A[i];
        // If no match found in loop, return the last element
        return A.back();
    }
};