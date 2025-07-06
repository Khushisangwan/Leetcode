#include<bits/stdc++.h>
using namespace std;
// This code defines a class FindSumPairs that allows for efficient querying of pairs of elements from two arrays that sum to a given value.
// It supports adding a value to an element in the second array and counting pairs that sum to a target value.
// The class uses an unordered map to keep track of the frequency of elements in the second array, allowing for O(1) average time complexity for updates and queries.

// Class to find pairs with a certain sum, supporting efficient updates and queries.
class FindSumPairs {
private:
    vector<int> n1, n2;                // Store the two input arrays
    unordered_map<int, int> m;         // Frequency map for elements in n2

public:
    // Constructor: initializes arrays and builds frequency map for n2
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1;
        n2 = nums2;
        for (int x : n2) {
            m[x]++;
        }
    }

    // Adds value v to n2[i] and updates the frequency map accordingly
    void add(int i, int v) {
        m[n2[i]]--;        // Decrement count of old value
        n2[i] += v;        // Update value
        m[n2[i]]++;        // Increment count of new value
    }

    // Counts the number of pairs (n1[x], n2[y]) such that n1[x] + n2[y] == t
    int count(int t) {
        int c = 0;
        for (int x : n1) {
            c += m[t - x]; // For each x in n1, add the count of (t-x) in n2
        }
        return c;
    }
};