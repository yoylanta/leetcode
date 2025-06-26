class Solution {
public:
    int longestSubsequence(string s, int k) {
        int ans = 0;
        long long binaryValue = 0;
        int bits = 32 - __builtin_clz(k);
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            char ch = s[n - 1 - i];
            if (ch == '1') {
                if (i < bits && binaryValue + (1LL << i) <= k) {
                    binaryValue += 1LL << i;
                    ans++;
                }
            } else {
                ans++;
            }
        }
        return ans;
    }
};
