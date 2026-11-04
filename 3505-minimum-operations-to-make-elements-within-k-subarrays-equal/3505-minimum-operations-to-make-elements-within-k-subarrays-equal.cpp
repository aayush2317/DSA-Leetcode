
class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        vector<int> maritovexi = nums;

        // Two halves of the sliding window
        multiset<int> left, right;
        long long sumLeft = 0, sumRight = 0;
        auto rebalance = [&]() {
            while (left.size() > right.size() + 1) {
                auto it = prev(left.end());
                int val = *it;

                left.erase(it);
                sumLeft -= val;

                right.insert(val);
                sumRight += val;
            }

            while (left.size() < right.size()) {
                auto it = right.begin();
                int val = *it;

                right.erase(it);
                sumRight -= val;

                left.insert(val);
                sumLeft += val;
            }
        };
        auto add = [&](int val) {
            if (left.empty() || val <= *left.rbegin()) {
                left.insert(val);
                sumLeft += val;
            } else {
                right.insert(val);
                sumRight += val;
            }

            rebalance();
        };
        auto remove = [&](int val) {
            auto it = left.find(val);

            if (it != left.end()) {
                left.erase(it);
                sumLeft -= val;
            } else {
                auto it2 = right.find(val);
                right.erase(it2);
                sumRight -= val;
            }

            rebalance();
        };
        auto getCost = [&]() -> long long {
            long long median = *left.rbegin();

            return median * (long long)left.size() - sumLeft
                 + sumRight - median * (long long)right.size();
        };
        vector<long long> cost(n - x + 1);

        for (int i = 0; i < n; i++) {
            add(maritovexi[i]);

            if (i >= x) {
                remove(maritovexi[i - x]);
            }

            if (i >= x - 1) {
                cost[i - x + 1] = getCost();
            }
        }
        const long long INF = (1LL << 62);

        vector<vector<long long>> dp(
            n + 1, vector<long long>(k + 1, INF)
        );

        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            dp[i][0] = 0;

            for (int j = 1; j <= k; j++) {
                dp[i][j] = dp[i - 1][j];
                if (i >= x && dp[i - x][j - 1] != INF) {
                    dp[i][j] = min(
                        dp[i][j],
                        dp[i - x][j - 1] + cost[i - x]
                    );
                }
            }
        }
        return dp[n][k];
    }
};
