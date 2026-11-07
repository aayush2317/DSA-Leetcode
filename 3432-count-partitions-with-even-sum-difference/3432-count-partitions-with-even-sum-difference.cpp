class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum=0;
        int ans=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            sum+=nums[i];
            int sum1=0;
            for(int j=i+1;j<nums.size();j++)
            {
                sum1+=nums[j];
            }
            int sub=abs(sum-sum1);
            if(sub%2==0)
            {
                ans++;
            }
        }
        return ans;
    }
};