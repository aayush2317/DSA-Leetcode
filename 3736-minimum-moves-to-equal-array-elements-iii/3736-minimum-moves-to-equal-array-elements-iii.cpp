class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int maxi=nums[0];
        for(int i=0;i<n;i++)
        {
            maxi=max(nums[i],maxi);
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            while(nums[i]!=maxi)
            {
                nums[i]++;
                count++;
            }

        }
        return count;
    }
};