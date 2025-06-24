class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> keyIndices, res;
        for(int i =0;i<nums.size();++i){
            if(nums[i]==key) keyIndices.push_back(i);
        }  
        for(int i=0;i<nums.size();++i){
            for(int j=0;j<keyIndices.size();++j){
                if(abs(i-keyIndices[j])<=k){
                    res.push_back(i); break;}
            }
        }return res;
    }
};