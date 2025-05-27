class Solution {
public:
    int differenceOfSums(int n, int m) {
        long long sum = 1LL * n * (n + 1) / 2;
        int k = n / m;
        long long num2 = 1LL * m * k * (k + 1) / 2;
        return sum - 2 * num2;
    }
};