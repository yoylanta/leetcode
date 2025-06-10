class Solution {
private:
    int* countFrequencies(const string& s){
        static int freq[256]={0};
        fill(begin(freq),end(freq),0);
        for(char c : s){
            freq[c]++;
        }
        return freq;
    }
public:
    int maxDifference(string s) {
        int* freq = countFrequencies(s);
        int maxOdd=numeric_limits<int>::min();
        int minEven=numeric_limits<int>::max();
        for(int i=0;i<256;++i){
            if(freq[i]>0){
            if(freq[i]%2==1){
                maxOdd=max(maxOdd,freq[i]);
            }
            else{
                minEven=min(minEven,freq[i]);
            }
            }
            
        }
        return maxOdd-minEven;
    }
};