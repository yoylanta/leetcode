class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int m[26][26] = {{0}};
        int length = 0;
        for (auto&w : words){
            int a = w[0] - 'a';
            int b = w[1] - 'a';
            if (m[b][a] > 0){
                length += 4;
                --m[b][a];
            }
            else{
                ++m[a][b];
            }
        }
        for (int i = 0; i < 26; ++i){
            if(m[i][i] > 0){
                length += 2;
                break;
            }
        }
        return length;
    }
};