class Solution {
public:
    string robotWithString(string s) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        string res = "";
        string t = "";
        for (char c : s) {
            t += c;
            freq[c - 'a']--;
            while (!t.empty()) {
                char smallest = 'a';
                while (smallest <= 'z' && freq[smallest - 'a'] == 0)
                    smallest++;
                if (t.back() <= smallest)
                    res += t.back(), t.pop_back();
                else
                    break;
            }
        }
        while (!t.empty()) {
            res += t.back();
            t.pop_back();
        }
        return res;
    }
};