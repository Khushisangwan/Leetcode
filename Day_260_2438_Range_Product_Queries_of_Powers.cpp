class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers, invpowers;
        
        for (int i = 1; i <= n; i <<= 1)
            if (n & i)
                powers.push_back(i);

        int allmult = 1;
        for (int i = 0; i < powers.size(); ++i)
            allmult = mult(allmult, powers[i]);

        invpowers.resize(powers.size());
        invpowers[powers.size() - 1] = inv(allmult);
        for (int i = powers.size() - 2; i >= 0; --i)
            invpowers[i] = mult(invpowers[i + 1], powers[i + 1]);

        for (int i = 1; i < powers.size(); ++i)
            powers[i] = mult(powers[i], powers[i - 1]);

        vector<int> ans;
        for (vector<int>& q : queries)
            ans.push_back(mult(powers[q[1]], q[0] > 0 ? invpowers[q[0] - 1] : 1));
        return ans;
    }

private:
    const int MOD = 1e9 + 7;

    int div(int a, int b) {
        return (int) (((1ll * a) * inv(b)) % MOD);
    }

    int mult(int a, int b) {
        return (int) (((1ll * a) * b) % MOD);
    }

    int inv(int num) {
        return binpow(num, MOD - 2);
    }

    int binpow(long long a, int b) {
        long long ret = 1;
        while (b) {
            if (b & 1) {
                ret *= a;
                ret %= MOD;
            }
            a *= a;
            a %= MOD;
            b /= 2;
        }
        return (int) ret;
    }
};