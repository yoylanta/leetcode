class Solution {
private:
    char nextChar(char c) {
        if (c >= 'a' && c <= 'z') {
            return (c == 'z') ? 'a' : c + 1;
        } else if (c >= 'A' && c <= 'Z') {
            return (c == 'Z') ? 'A' : c + 1;
        }
        return c;
    }
public:
    char kthCharacter(int k) {
        string word = "a";
        while(word.size()<k){
            int n = word.size();
            for(int i=0;i<n;++i){
                word+=nextChar(word[i]);
            }
        } return word[k-1];
    }
};