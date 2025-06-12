class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxDiff = INT_MIN;
        for(int i =0; i <nums.size()-1;++i){
            if(abs(nums[i+1]-nums[i])>maxDiff) maxDiff = abs(nums[i+1]-nums[i]);
        }
        if(abs(nums[nums.size()-1]-nums[0])>maxDiff) maxDiff = abs(nums[nums.size()-1]-nums[0]);
        return maxDiff;
    }
};