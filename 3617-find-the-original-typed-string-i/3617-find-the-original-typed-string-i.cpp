class Solution {
public:
    int possibleStringCount(string word) {
        int res = 1, curr = 1;
        for (int i = 1; i < word.size(); ++i) {
            if (word[i] == word[i-1]) {
                ++curr;
            } else {
                res += curr - 1;
                curr = 1;
            }
        }
        res += curr - 1;
        return res;

    }
};