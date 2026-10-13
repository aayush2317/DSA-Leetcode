class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
         int n = nums.size();

        vector<long long> sq;

        for(int x : nums) {
            sq.push_back(1LL * x * x);
        }

        sort(sq.begin(), sq.end());

        long long score = 0;

        int negativeCount = n / 2;

        for(int i = 0; i < n; i++) {
            if(i < negativeCount)
                score -= sq[i];
            else
                score += sq[i];
        }

        return score;
    }
};