
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp = {0, -1000000000, -1000000000};

        for (int x : nums) {
            vector<int> temp = dp;

            temp[x % 3] = max(temp[x % 3], dp[0] + x);
            temp[(1 + x) % 3] = max(temp[(1 + x) % 3], dp[1] + x);
            temp[(2 + x) % 3] = max(temp[(2 + x) % 3], dp[2] + x);

            dp = temp;
        }

        return dp[0];
    }
};
