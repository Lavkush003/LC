class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        // {weight, index}
        priority_queue<pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>> available;

        // {freeTime, weight, index}
        priority_queue<tuple<long long, int, int>,
            vector<tuple<long long, int, int>>,
            greater<tuple<long long, int, int>>> busy;

        int n = servers.size();
        int m = tasks.size();

        for (int i = 0; i < n; i++) {
            available.push({servers[i], i});
        }

        vector<int> ans(m);
        long long currTime = 0;

        for (int i = 0; i < m; i++) {

            // Update current time
            currTime = max(currTime, (long long)i);

            // Release servers that have completed their tasks
            while (!busy.empty() &&
                   get<0>(busy.top()) <= currTime) {

                auto [freeTime, weight, index] = busy.top();
                busy.pop();

                available.push({weight, index});
            }

            // If no server is available, move time forward
            if (available.empty()) {

                currTime = get<0>(busy.top());

                while (!busy.empty() &&
                       get<0>(busy.top()) <= currTime) {

                    auto [freeTime, weight, index] = busy.top();
                    busy.pop();

                    available.push({weight, index});
                }
            }

            // Choose server with minimum weight, then minimum index
            auto [weight, index] = available.top();
            available.pop();

            ans[i] = index;

           
            busy.push({
                currTime + (long long)tasks[i],
                weight,
                index
            });
        }

        return ans;
    }
};