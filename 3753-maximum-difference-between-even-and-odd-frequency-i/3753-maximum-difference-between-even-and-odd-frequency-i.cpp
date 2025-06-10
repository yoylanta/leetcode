class Solution {
private:
    unordered_map<char,int> countFrequencies(const string& s){
        unordered_map<char,int> freq;
        for(char c : s){
            freq[c]++;
        }
        return freq;
    }
public:
    int maxDifference(string s) {
        unordered_map<char,int> freq = countFrequencies(s);
        int maxOdd=numeric_limits<int>::min();
        int minEven=numeric_limits<int>::max();
        for(const auto& pair : freq){
            if(pair.second%2==1){
                maxOdd=max(maxOdd,pair.second);
            }
            else{
                minEven=min(minEven,pair.second);
            }
        }
        return maxOdd-minEven;
    }
};