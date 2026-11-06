class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {

        sort(logs.begin(), logs.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[1] < b[1];
             });

        vector<pair<int, int>> q;

        for (int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        vector<int> ans(queries.size());
        vector<int> freq(n + 1, 0);

        int left = 0;
        int right = 0;
        int active = 0;

        for (auto& p : q) {

            int time = p.first;
            int idx = p.second;

            int start = time - x;

            // Add logs inside the current right boundary
            while (right < logs.size() &&
                   logs[right][1] <= time) {

                int id = logs[right][0];

                if (freq[id] == 0) {
                    active++;
                }

                freq[id]++;
                right++;
            }

            // Remove logs outside the left boundary
            while (left < right &&
                   logs[left][1] < start) {

                int id = logs[left][0];

                freq[id]--;

                if (freq[id] == 0) {
                    active--;
                }

                left++;
            }

            ans[idx] = n - active;
        }

        return ans;
    }
};