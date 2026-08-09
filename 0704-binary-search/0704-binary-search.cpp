class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lb=0;
        int ub=nums.size()-1;
        int mid=(lb+ub)/2;
        while(lb<=ub)
        {
        if(nums[mid]==target)
        {
            return mid;
        }
        else if(nums[mid]<target)
        {
            lb=mid+1;
            mid=(lb+ub)/2;
        }
        else
        {
            ub=mid-1;
            mid=(lb+ub)/2;
        }
        }
        return -1;
    }
};