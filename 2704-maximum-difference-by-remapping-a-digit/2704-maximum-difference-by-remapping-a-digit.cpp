class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string maxStr = s;
        for (char c : s) {
            if (c != '9') {
                char toReplace = c;
                for (char &ch : maxStr) {
                    if (ch == toReplace) ch = '9';
                }
                break;
            }
        }
        string minStr = s;
        for (char c : s) {
            if (c != '0') {
                char toReplace = c;
                for (char &ch : minStr) {
                    if (ch == toReplace) ch = '0';
                }
                break;
            }
        }
        int maxNum = stoi(maxStr);
        int minNum = stoi(minStr);
        return maxNum - minNum;
    }
};