class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        int posindex=0;
        int negindex=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
            {
                ans[posindex]=nums[i];
                posindex+=2;
            }
            else
            {
                ans[negindex]=nums[i];
                negindex+=2;
            }
        }
        return ans;
    }
};