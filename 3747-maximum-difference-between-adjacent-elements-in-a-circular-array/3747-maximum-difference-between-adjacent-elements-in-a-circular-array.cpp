class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxDiff = abs(nums[0]-nums[nums.size()-1]);
        int n = nums.size()-1;
        for(int i =0; i <n;++i){
           maxDiff=max(maxDiff, abs(nums[i+1]-nums[i]));
        }
        return maxDiff;
    }
};