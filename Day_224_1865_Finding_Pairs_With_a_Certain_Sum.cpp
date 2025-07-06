#include<bits/stdc++.h>
using namespace std;
// This code defines a class FindSumPairs that allows for efficient querying of pairs of elements from two arrays that sum to a given value.
// It supports adding a value to an element in the second array and counting pairs that sum to a target value.
// The class uses an unordered map to keep track of the frequency of elements in the second array, allowing for O(1) average time complexity for updates and queries.

class FindSumPairs {
private:
    vector<int> n1, n2;
    unordered_map<int, int> m;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1;
        n2 = nums2;
        for (int x : n2) {
            m[x]++;
        }
    }

    void add(int i, int v) {
        m[n2[i]]--;
        n2[i] += v;
        m[n2[i]]++;
    }

    int count(int t) {
        int c = 0;
        for (int x : n1) {
            c += m[t - x];
        }
        return c;
    }
};