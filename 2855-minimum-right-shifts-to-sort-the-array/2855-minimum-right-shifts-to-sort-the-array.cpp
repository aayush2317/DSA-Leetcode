class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] > nums[(i + 1) % n]) {
                count++;
            }
        }

        if(count > 1)
            return -1;

        for(int i = 0; i < n; i++) {
            if(nums[i] > nums[(i + 1) % n]) {
                return n - i - 1;
            }
        }

        return 0;
    }
};