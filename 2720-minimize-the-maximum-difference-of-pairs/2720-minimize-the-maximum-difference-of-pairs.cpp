class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        if (p == 0) return 0;
        sort(nums.begin(), nums.end());
        int low = 0;
        int high = nums.back() - nums.front();
        auto canForm = [&](int maxDiff) {
            int formed = 0;
            for (int i = 1; i < nums.size() && formed < p; ++i) {
                if (nums[i] - nums[i - 1] <= maxDiff) {
                    formed++;
                    ++i;
                }
            }
            return formed >= p;
        };
        while (low < high) {
            int mid = low + ((high - low) >> 1);
            if (canForm(mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};