class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size() - 1, ans = abs(nums[n] - nums[0]);
        for (int i = 0; i < n; ++i) {
            ans = max(ans, abs(nums[i] - nums[i + 1]));
        }

        return ans;
    }
};