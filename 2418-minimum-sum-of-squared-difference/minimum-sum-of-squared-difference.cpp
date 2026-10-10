class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;

        vector<int> diff(n);
        int mx = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            mx = max(mx, diff[i]);
        }

        long long total = 0;
        for (int d : diff) {
            total += d;
        }

        // If all differences can become zero
        if (k >= total) {
            return 0;
        }

        int low = 0, high = mx;

        // Find the minimum possible maximum difference
        while (low < high) {
            int mid = low + (high - low) / 2;
            long long needed = 0;

            for (int d : diff) {
                if (d > mid) {
                    needed += d - mid;
                }
            }

            if (needed <= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        int level = low;
        long long ans = 0;
        long long remaining = k;

        // Reduce every difference to at most 'level'
        for (int d : diff) {
            if (d > level) {
                remaining -= d - level;
                d = level;
            }
            ans += 1LL * d * d;
        }

        // Distribute leftover operations by reducing
        // some differences from 'level' to 'level - 1'
        if (level > 0) {
            long long count = remaining;
            ans -= count * (2LL * level - 1);
        }

        return ans;
    }
};