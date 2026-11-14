
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();

        vector<long long> prefix(n + 1, 0);

        for(int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        multiset<long long> st;

        long long ans = LLONG_MAX;

        for(int j = 1; j <= n; j++) {

            if(j - l >= 0) {
                st.insert(prefix[j - l]);
            }

            if(j - r - 1 >= 0) {
                auto it = st.find(prefix[j - r - 1]);
                if(it != st.end()) {
                    st.erase(it);
                }
            }

            auto it = st.lower_bound(prefix[j]);

            if(it != st.begin()) {
                --it;

                long long sum = prefix[j] - *it;

                ans = min(ans, sum);
            }
        }

        return ans == LLONG_MAX ? -1 : (int)ans;
    }
};
