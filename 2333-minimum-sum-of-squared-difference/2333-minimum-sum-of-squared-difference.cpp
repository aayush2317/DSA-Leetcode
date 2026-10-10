class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int> diff(n);

        long long k = (long long)k1 + k2;
        long long total = 0;
        int high = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
            high = max(high, diff[i]);
        }

        if (total <= k) return 0;

        int low = 0;

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long operations = 0;

            for (int x : diff) {
                if (x > mid) {
                    operations += x - mid;
                }
            }

            if (operations <= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        int target = low;

        for (int& x : diff) {
            if (x > target) {
                k -= x - target;
                x = target;
            }
        }

        long long sum = 0;

        for (int x : diff) {
            if (x == target && k > 0) {
                x--;
                k--;
            }
            sum += 1LL * x * x;
        }
        return sum;

    }
};