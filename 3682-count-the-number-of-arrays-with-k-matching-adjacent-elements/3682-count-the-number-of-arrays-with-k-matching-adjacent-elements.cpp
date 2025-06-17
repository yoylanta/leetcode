class Solution {
    static constexpr int MOD = 1'000'000'007;
    static constexpr int MAXN = 100'005;

    vector<long long> fact, inv_fact;

    long long mod_pow(long long base, long long exp, int mod = MOD) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1)
                result = (result * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }

    long long mod_inv(long long a, int mod = MOD) {
        return mod_pow(a, mod - 2, mod);
    }

    void precompute_factorials(int limit) {
        fact.resize(limit + 1);
        inv_fact.resize(limit + 1);
        fact[0] = 1;
        for (int i = 1; i <= limit; ++i)
            fact[i] = fact[i - 1] * i % MOD;

        inv_fact[limit] = mod_inv(fact[limit]);
        for (int i = limit - 1; i >= 0; --i)
            inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    }

    long long binomial(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
    }

public:
    int countGoodArrays(int n, int m, int k) {
        precompute_factorials(n);
        long long combinations = binomial(n - 1, k);
        long long power = mod_pow(m - 1, n - 1 - k);
        long long result = combinations * m % MOD * power % MOD;
        return static_cast<int>(result);
    }
};
