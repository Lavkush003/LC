
class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        multiset<int> left, right;
        long long sumL = 0, sumR = 0;

        // Balance two multisets around the median
        auto balance = [&]() {
            int target = (left.size() + right.size() + 1) / 2;

            while (left.size() > target) {
                int val = *left.rbegin();
                left.erase(prev(left.end()));
                sumL -= val;

                right.insert(val);
                sumR += val;
            }

            while (left.size() < target) {
                int val = *right.begin();
                right.erase(right.begin());
                sumR -= val;

                left.insert(val);
                sumL += val;
            }
        };

        // Insert an element
        auto add = [&](int val) {
            if (left.empty() || val <= *left.rbegin()) {
                left.insert(val);
                sumL += val;
            } else {
                right.insert(val);
                sumR += val;
            }
            balance();
        };

        // Remove an element
        auto remove = [&](int val) {
            auto it = left.find(val);

            if (it != left.end()) {
                left.erase(it);
                sumL -= val;
            } else {
                it = right.find(val);
                right.erase(it);
                sumR -= val;
            }

            balance();
        };

        // Calculate minimum cost for every window
        vector<long long> cost(n - x + 1);

        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1) {
                long long median = *left.rbegin();

                long long leftCost =
                    median * (long long)left.size() - sumL;

                long long rightCost =
                    sumR - median * (long long)right.size();

                cost[i - x + 1] = leftCost + rightCost;
            }
        }

        // Dynamic Programming
        const long long INF = LLONG_MAX / 4;

        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, INF);

        for (int j = 1; j <= k; j++) {
            fill(curr.begin(), curr.end(), INF);

            for (int i = 1; i <= n; i++) {

                // Option 1: Skip current element
                curr[i] = curr[i - 1];

                // Option 2: Select a window of size x
                if (i >= x) {
                    curr[i] = min(
                        curr[i],
                        prev[i - x] + cost[i - x]
                    );
                }
            }

            prev.swap(curr);
        }

        return prev[n];
    }
};
