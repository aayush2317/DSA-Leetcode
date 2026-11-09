class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int position=0;
        for(int i=0;i<n;i++)
        {
            position+=nums[i];
            if(position==0) count++;
        }
        return count; 
    }
};