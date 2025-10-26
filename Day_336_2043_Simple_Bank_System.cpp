#include<bits/stdc++.h>
using namespace std;
// Simple Bank system that supports deposit, withdraw and transfer operations.
// Accounts are 1-indexed externally but stored 0-indexed in the vector.
class Bank {
private:
    // balances for each account (0-indexed internally)
    vector<long long> bal;
    // number of accounts
    int n;

    // helper: check whether an account index (1-indexed) is valid
    bool valid(int acc) {
        return acc > 0 && acc <= n;
    }

public:
    // Construct the bank with initial balances.
    // `balance[i]` is the balance of account (i+1).
    Bank(vector<long long>& balance) {
        bal = balance;
        n = balance.size();
    }

    // Transfer `amt` from account `from` to account `to`.
    // Returns true if successful (accounts valid and sufficient funds), false otherwise.
    bool transfer(int from, int to, long long amt) {
        if (!valid(from) || !valid(to) || bal[from - 1] < amt) return false;
        bal[from - 1] -= amt;
        bal[to - 1] += amt;
        return true;
    }

    // Deposit `amt` into account `acc`. Returns false if account invalid.
    bool deposit(int acc, long long amt) {
        if (!valid(acc)) return false;
        bal[acc - 1] += amt;
        return true;
    }

    // Withdraw `amt` from account `acc`. Returns false if account invalid or insufficient funds.
    bool withdraw(int acc, long long amt) {
        if (!valid(acc) || bal[acc - 1] < amt) return false;
        bal[acc - 1] -= amt;
        return true;
    }
};