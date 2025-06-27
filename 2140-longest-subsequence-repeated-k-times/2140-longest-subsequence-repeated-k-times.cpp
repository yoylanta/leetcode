class Solution {
private:
    bool isValid(const string& s, const string& candidate, int k){
        int i=0, count=0;
        for(char c:s){
            if(c==candidate[i]){
                i++;
                if(i==candidate.size()){
                    i=0; count++;
                    if(count==k) return true;
                }
            }
        }return false;
    }

    bool dfs(string& curr, const vector<char>& chars, int maxLen, const string& s, int k, string& res){
        if(curr.size()==maxLen) {
            if(isValid(s,curr,k)){
                res=curr;
                return true;
            }return false;
        }
        for(char c: chars){
            curr.push_back(c);
            if(isValid(s,curr,k)){
if(dfs(curr,chars,maxLen,s,k,res)) return true;
            }
        
            curr.pop_back();
        }return false;
    }

public:
    string longestSubsequenceRepeatedK(string s, int k) {
        unordered_map<char,int> freq;
        int n=s.size();
        for(char c:s) freq[c]++;
        vector<char> validChars;
        for(auto& [c,count] : freq){
            if(count>=k) validChars.push_back(c);
        }
        if(validChars.empty()) return "";
        string validS;
        for(char c :s){
            if(freq[c]>=k) validS.push_back(c);
        } s = validS;
        sort(validChars.rbegin(),validChars.rend());

        string res = "", curr = "";
        int maxLen=n/k;
        for(int len=maxLen; len>=1;--len){
            if(dfs(curr,validChars, len, s, k, res)) break;
        }
        
        return res;
    }
};