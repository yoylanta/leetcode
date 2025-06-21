class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> freq_map;
        for (char ch : word) ++freq_map[ch];
        vector<int> freqs;
        for (auto& [_, freq] : freq_map) freqs.push_back(freq);
        int res = word.size();
        for (int base : freqs) {
            int del = 0;
            for (int f : freqs) {
                if (f < base) del += f;
                else if (f > base + k) del += f - (base + k);
            }
            res = min(res, del);
        }
        return res;
    }
};