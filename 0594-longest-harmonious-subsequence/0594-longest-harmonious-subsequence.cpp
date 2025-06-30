class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int i : nums){
            freq[i]++;
        }
        int res=0;
        for(const auto& [i, frequency] : freq){
            if(freq.count(i+1)){
                res=max(res,frequency+freq[i+1]);
            }
        }return res;
    }
};