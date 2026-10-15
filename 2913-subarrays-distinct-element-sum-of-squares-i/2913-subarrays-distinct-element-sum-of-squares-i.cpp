class Solution {
public:
    int sumCounts(vector<int>& nums) {
        set<int> st;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            st.clear();
            for(int j=i;j<nums.size();j++)
            {
                st.insert(nums[j]);
                int size=st.size();
                ans+=size*size;
            }
        }
        return ans;
    }
};