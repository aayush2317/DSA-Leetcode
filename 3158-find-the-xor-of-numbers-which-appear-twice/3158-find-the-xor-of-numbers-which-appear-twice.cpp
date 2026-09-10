class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        set<int>st;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(st.count(nums[i]))
            {
                ans=ans^nums[i];
            }
            else
            {
                st.insert(nums[i]);
            }
        }
        return ans;
    }
};