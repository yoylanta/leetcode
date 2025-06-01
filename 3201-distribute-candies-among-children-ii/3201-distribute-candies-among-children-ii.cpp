class Solution {
public:
    long long countWays(int sum) {
        if (sum < 0) return 0;
        return 1LL * (sum + 2) * (sum + 1) / 2;
    }

    long long distributeCandies(int n, int limit) {
        long long total = countWays(n);
        for (int i = 1; i <= 3; ++i) {
            int over = n - i * (limit + 1);
            if (over < 0) break;
            long long ways = countWays(over);
            int coeff = (i % 2 == 1 ? -1 : 1) * (i == 3 ? 1 : 3);
            total += coeff * ways;
        }
        return total;;
    }
};