class Solution {
public:
    int findmax(vector<int> &piles)
    {
        int maxi=INT_MIN;
        int n=piles.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,piles[i]);
        }
        return maxi;
    }
    long long totalhour(vector<int> &piles,int hourly)
    {
        long long totalH=0;
        int n=piles.size();
        for(int i=0;i<n;i++)
        {
            totalH+=ceil((double)piles[i]/(double)hourly);
        }
        return totalH;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=findmax(piles);
        while(low<=high)
        {
            int mid=(low+high)/2;
            long long totalh=totalhour(piles,mid);
            if(totalh<=h)
            {
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};