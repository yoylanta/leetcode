class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int n = s.size();
        int i = 0;
        while (i < n) {
            while (i < n && s[i] == ' ') i++;
            if (i >= n) break;
            int start = i;
            while (i < n && s[i] != ' ') i++;
            words.emplace_back(s.substr(start, i - start));
        }
        string ans;
        for (int k = words.size() - 1; k >= 0; --k) {
            ans += words[k];
            if (k > 0) ans += ' ';
        }
        return ans;
    }
};