class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxDiff = abs(nums[0]-nums[nums.size()-1]);
        for(int i =0; i <nums.size()-1;++i){
           maxDiff=max(maxDiff, abs(nums[i+1]-nums[i]));
        }
        return maxDiff;
    }
};