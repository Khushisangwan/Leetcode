#include<bits/stdc++.h>
using namespace std;
// LeetCode 2040. Kth Smallest Product of Two Sorted Arrays
// https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/
class Solution {
 public:
    // Main function to find the k-th smallest product
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2,
                                                             long long k) {
        vector<int> A1; // Negative numbers from nums1 (stored as positive)
        vector<int> A2; // Non-negative numbers from nums1
        vector<int> B1; // Negative numbers from nums2 (stored as positive)
        vector<int> B2; // Non-negative numbers from nums2

        // Separate nums1 and nums2 into negative and non-negative parts
        seperate(nums1, A1, A2);
        seperate(nums2, B1, B2);

        // Count of negative products
        const long negCount = A1.size() * B2.size() + A2.size() * B1.size();
        int sign = 1; // 1 for positive, -1 for negative

        if (k > negCount) {
            // If k is greater than the number of negative products,
            // find the (k - negCount)-th positive product
            k -= negCount;
        } else {
            // Otherwise, find the (negCount - k + 1)-th smallest absolute negative product
            k = negCount - k + 1;
            sign = -1;
            swap(B1, B2); // Swap to search in the correct product pairs
        }

        long l = 0;
        long r = 1e10; // Binary search range for the product value

        // Binary search for the k-th smallest product
        while (l < r) {
            const long m = (l + r) / 2;
            // Count products <= m in both (A1, B1) and (A2, B2) pairs
            if (numProductNoGreaterThan(A1, B1, m) +
                            numProductNoGreaterThan(A2, B2, m) >=
                    k)
                r = m;
            else
                l = m + 1;
        }

        return sign * l;
    }

 private:
    // Separate input array A into negative (A1, stored as positive) and non-negative (A2)
    void seperate(const vector<int>& A, vector<int>& A1, vector<int>& A2) {
        for (const int a : A)
            if (a < 0)
                A1.push_back(-a);
            else
                A2.push_back(a);
        reverse(begin(A1), end(A1)); // Reverse to maintain sorted order
    }

    // Count number of pairs (a, b) with a in A, b in B, such that a * b <= m
    long numProductNoGreaterThan(const vector<int>& A, const vector<int>& B,
                                                             long m) {
        long count = 0;
        int j = B.size() - 1;
        for (const long a : A) {
            // Move j left while product exceeds m
            while (j >= 0 && a * B[j] > m)
                --j;
            count += j + 1; // All B[0..j] are valid for this a
        }
        return count;
    }
};