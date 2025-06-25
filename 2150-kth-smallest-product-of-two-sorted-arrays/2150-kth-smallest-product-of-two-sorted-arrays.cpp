using ll = long long;
class Solution {
public:
    int n, m;
    ll get_count(vector<int>& nums1, vector<int>& nums2, ll prod) {
        ll count = 0;
        for (auto num : nums1) {
            if (num == 0) {
                if (prod >= 0) count += m;
                continue;
            }
            ll b = prod == 0 ? 0 : prod / num;
            if (prod < 0) {
                if (num < 0) b += (prod % num != 0);
                else b -= (prod % num != 0);
            }
            int l = 0, r = m - 1, ans = -1, mid;
            if (num < 0) {
                while (l <= r) {
                    mid = (l + r) >> 1;
                    if (nums2[mid] >= b) {
                        ans = mid;
                        r = mid - 1;
                    } else l = mid + 1;
                }
                if (ans != -1) count += m - ans;
            } else {
                while (l <= r) {
                    mid = (l + r) >> 1;
                    if (nums2[mid] <= b) {
                        ans = mid;
                        l = mid + 1;
                    } else r = mid - 1;
                }
                if (ans != -1) count += ans + 1;
            }
        }
        return count;
    }
    ll kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, ll k) {
        n = nums1.size(), m = nums2.size();
        ll l = -1e10, r = 1e10, mid, ans = -1;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (get_count(nums1, nums2, mid) >= k) {
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        return ans;
    }
};
