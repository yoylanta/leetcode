class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minVal=nums[0];
        int maxDiff = -1;
        for(int i=1;i<nums.size();++i){
            if(nums[i]>minVal){maxDiff=max(nums[i]-minVal, maxDiff);}
            else {minVal=nums[i];}
        }
        return maxDiff;
    }
};