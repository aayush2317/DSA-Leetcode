class Solution {
public:
    int sortableIntegers(std::vector<int>& nums) {
        int n = nums.size();
        
        // Find all divisors of n
        std::vector<int> divisors;
        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                divisors.push_back(i);
                if (i * i != n) {
                    divisors.push_back(n / i);
                }
            }
        }

        int total_sum = 0;

        for (int k : divisors) {
            bool valid = true;
            int prev_max = -1; // Keep track of maximum element of the previous sorted block

            for (int i = 0; i < n; i += k) {
                // Check block nums[i ... i + k - 1]
                int drops = 0;
                int drop_idx = -1;

                for (int j = 0; j < k - 1; ++j) {
                    if (nums[i + j] > nums[i + j + 1]) {
                        drops++;
                        drop_idx = j;
                    }
                }

                int block_min, block_max;

                if (drops == 0) {
                    block_min = nums[i];
                    block_max = nums[i + k - 1];
                } else if (drops == 1) {
                    // Cyclic rotation is valid only if last element <= first element
                    if (nums[i + k - 1] > nums[i]) {
                        valid = false;
                        break;
                    }
                    block_min = nums[i + drop_idx + 1];
                    block_max = nums[i + drop_idx];
                } else {
                    // More than 1 drop cannot be sorted by rotation
                    valid = false;
                    break;
                }

                // Check condition between consecutive blocks
                if (prev_max != -1 && block_min < prev_max) {
                    valid = false;
                    break;
                }

                prev_max = block_max;
            }

            if (valid) {
                total_sum += k;
            }
        }

        return total_sum;
    }
};