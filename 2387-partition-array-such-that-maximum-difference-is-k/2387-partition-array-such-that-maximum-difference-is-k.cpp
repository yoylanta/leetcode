class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int answer = 1, min_value = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] - min_value > k) {
                answer++;
                min_value = nums[i];
            }
        }
        return answer; 
    }
};