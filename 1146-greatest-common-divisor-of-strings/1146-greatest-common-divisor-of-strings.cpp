class Solution {
private:
    bool devides(string str1, string str2){
        int n = str1.size(), m=str2.size();
        if (n % m != 0) return false;
        for(int i = 0; i < n; ++i){
            if(str1[i]!=str2[i%m]) return false;
        }
        return true;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        int maxGCDlen = min(str1.size(),str2.size());
        string ans = "";
        for(int len = 1; len<=maxGCDlen;++len){
            if(str1.size()%len!=0 || str2.size()%len!=0) continue;
            string prefix = str1.substr(0,len);
            if(devides(str1, prefix) && devides(str2, prefix)){
                if(prefix.size()>ans.size()) ans=prefix;
            }
        }return ans;
    }
};