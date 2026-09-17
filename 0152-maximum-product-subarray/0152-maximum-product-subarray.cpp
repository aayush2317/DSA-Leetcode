class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxproduct=INT_MIN;
        int pre=1,suf=1;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(pre==0) pre=1;
            if(suf==0) suf=1;
            pre=pre*nums[i];
            suf=suf*nums[n-i-1];
            maxproduct=max(maxproduct,max(pre,suf));
        }
        return maxproduct;
    }
};