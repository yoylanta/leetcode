class Solution {
public:
    string reverseVowels(string s) {
        set<char> vowels = {'a','A','e','E','u','U','i','I','o','O'};
        int start = 0, end = s.size()-1;
        while(start<end){
            while(start<end && vowels.find(s[start])==vowels.end()) start++;
            while(start<end && vowels.find(s[end])==vowels.end()) end--;
            swap(s[start],s[end]);
            start++; end--;
        }
        return s;
    }
};