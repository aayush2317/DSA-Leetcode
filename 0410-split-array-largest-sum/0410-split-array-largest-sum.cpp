class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            low=max(low,nums[i]);
        }
        int high=0;
        for(int i=0;i<n;i++)
        {
            high+=nums[i];
        }
        while(low<=high)
        {
            int mid=(low+high)/2;
            int sum=0;
            int subarray=1;
            for(int i=0;i<n;i++)
            {
                if(sum+nums[i]<=mid)
                {
                   sum=sum+nums[i];
                }
                else
                {
                    subarray++;
                    sum=nums[i];
                }
            }
            if(subarray<=k)
            {
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};