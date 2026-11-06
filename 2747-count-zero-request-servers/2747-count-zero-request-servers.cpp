
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {

        int L = logs.size();
        int Q = queries.size();
        sort(logs.begin(), logs.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[1] < b[1];
             });

        vector<pair<int, int>> q;

        for (int i = 0; i < Q; i++) {
            q.push_back({queries[i], i});
        }
        sort(q.begin(), q.end());

        vector<int> ans(Q);
        vector<int> freq(n + 1, 0);

        int left = 0;
        int right = 0;
        int active = 0;

        for (auto [time, idx] : q) {
            while (right < L && logs[right][1] <= time) {

                int server = logs[right][0];

                if (freq[server] == 0) {
                    active++;
                }

                freq[server]++;
                right++;
            }

            while (left < right && logs[left][1] < time - x) {

                int server = logs[left][0];

                freq[server]--;

                if (freq[server] == 0) {
                    active--;
                }

                left++;
            }
            ans[idx] = n - active;
        }

        return ans;
    }
};
