class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int low=0;
        for(int i=0;i<n;i++)
        {
            low=max(low,weights[i]);
        }
        int high=0;
        for(int i=0;i<n;i++)
        {
            high+=weights[i];
        }
        while(low<=high)
        {
            int mid=(low+high)/2;
            int daysneeded=1;
            int sum=0;
            for(int i=0;i<n;i++)
            {
                if(sum+weights[i]<=mid)
                {
                    sum+=weights[i];
                }
                else
                {
                    daysneeded++;
                    sum = weights[i];
                }
            }
            if(daysneeded<=days)
            {
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};