class Solution {
    bool isRotation(vector<int>& nums,
                    vector<int>& target,
                    int start,
                    int k)
    {
        // Build LPS array for target block
        vector<int> lps(k, 0);

        for(int i = 1, len = 0; i < k; )
        {
            if(target[start + i] == target[start + len])
            {
                lps[i] = len + 1;
                i++;
                len++;
            }
            else
            {
                if(len > 0)
                    len = lps[len - 1];
                else
                    i++;
            }
        }

        int j = 0;

        // Search target block inside
        // original block + original block
        for(int i = 0; i < 2 * k - 1; i++)
        {
            int value = nums[start + (i % k)];

            while(j > 0 && value != target[start + j])
            {
                j = lps[j - 1];
            }

            if(value == target[start + j])
            {
                j++;
            }

            if(j == k)
                return true;
        }

        return false;
    }

    bool possible(vector<int>& nums,
                  vector<int>& target,
                  int k)
    {
        int n = nums.size();

        // Check every block of size k
        for(int start = 0; start < n; start += k)
        {
            if(!isRotation(nums, target, start, k))
                return false;
        }

        return true;
    }

public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        // Final sorted array
        vector<int> target = nums;
        sort(target.begin(), target.end());

        long long ans = 0;

        // Find divisors of n
        for(int k = 1; k * k <= n; k++)
        {
            if(n % k != 0)
                continue;

            // First divisor
            if(possible(nums, target, k))
            {
                ans += k;
            }

            // Second divisor
            int other = n / k;

            if(other != k)
            {
                if(possible(nums, target, other))
                {
                    ans += other;
                }
            }
        }

        return ans;
    }
};