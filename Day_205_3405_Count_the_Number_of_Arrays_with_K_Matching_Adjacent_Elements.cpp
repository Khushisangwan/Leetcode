#include <bits/stdc++.h>
using namespace std;
// 3405. Count the Number of Arrays with K Matching Adjacent Elements
// This code defines a solution to count the number of arrays with exactly k matching adjacent elements.

const int MOD = 1e9 + 7; // Modulo for large numbers

class Solution {
public:
    // Computes modular inverse of a under modulo mod using Fermat's Little Theorem
    long long modInverse(long long a, long long mod){
        long long res = 1;
        long long power = mod - 2;

        while (power){
            if (power & 1)
                res = res * a % mod;
            a = a * a % mod;
            power >>= 1;
        }

        return res;
    }

    // Computes nCr % MOD using modular inverse
    int nCr(int n, int r){
        if (r > n) return 0;
        if (r == 0 || r == n) return 1;

        long long res = 1;

        for (int i = 1; i <= r; i++){
            res = res * (n - r + i) % MOD;
            res = res * modInverse(i, MOD) % MOD;
        }

        return (int)res;
    }

    // Fast exponentiation: computes (a^b) % MOD
    long long bin_expo(long long a, long long b)
    {
        long long result = 1;
        while (b) {
            if (b & 1)
                result = (result * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return result;
    }

    // Main function to count arrays with exactly k matching adjacent elements
    int countGoodArrays(int n, int m, int k) {
        // Number of ways to fill the array with exactly k matching adjacent pairs:
        // 1. Choose k positions for matching pairs: C(n-1, k)
        // 2. For the first element: m choices
        // 3. For each non-matching position: (m-1) choices
        int formula = (m * 1ll * bin_expo(m-1, n-(k+1))) % MOD;

        // Multiply by the number of ways to choose k matching positions
        int updated_formula = (formula * 1ll * nCr(n-1, k)) % MOD; 

        return updated_formula;
    }
};