class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans(n / 3, vector<int>(3));
        for (int i = 0, g = 0; i < n; i += 3, ++g) {
            if (nums[i + 2] - nums[i] > k) return {};
            ans[g][0] = nums[i];
            ans[g][1] = nums[i + 1];
            ans[g][2] = nums[i + 2];
        }
        return ans;
    }
};