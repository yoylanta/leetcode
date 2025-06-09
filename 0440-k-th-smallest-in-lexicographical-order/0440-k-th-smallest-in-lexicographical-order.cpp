class Solution {
public:
    long long getCount(long long prefix, long long n) {
        long long count = 0, curr = prefix, next = prefix + 1;
        while (curr <= n) {
            count += min(n + 1LL, next) - curr;
            curr *= 10;
            next *= 10;
        }
        return count;
    }
    int findKthNumber(int n, int k) {
        int curr = 1;
        --k;
        while (k > 0) {
            long long count = getCount(curr, n);
            if (count <= k) {
                ++curr;
                k -= count;
            } else {
                curr *= 10;
                --k;
            }
        }
        return curr;
    }
};