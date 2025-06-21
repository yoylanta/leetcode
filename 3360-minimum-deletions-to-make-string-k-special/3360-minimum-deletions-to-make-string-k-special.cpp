class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);
        for (char c : word) ++freq[c - 'a'];
        sort(freq.begin(), freq.end());
        int total_deleted = 0, min_deletions = word.size();
        for (int i = 0; i < 26; ++i) {
            if (freq[i] == 0) continue;
            int current = total_deleted;
            for (int j = 25; j > i && freq[j] - freq[i] > k; --j) {
                current += freq[j] - freq[i] - k;
            }
            min_deletions = min(min_deletions, current);
            total_deleted += freq[i];
        }
        return min_deletions;
    }
};