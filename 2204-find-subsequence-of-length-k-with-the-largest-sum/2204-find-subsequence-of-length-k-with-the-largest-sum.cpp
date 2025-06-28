class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return nums[a] > nums[b];
        });
        vector<int> top_k_indices(indices.begin(), indices.begin() + k);
        sort(top_k_indices.begin(), top_k_indices.end());
        vector<int> res;
        for (int idx : top_k_indices) {
            res.push_back(nums[idx]);
        }
        return res;
    }
};