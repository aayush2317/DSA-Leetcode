class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int digit=0;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            int digitcount=0;
            digit=nums[i];
            while(digit>0)
            {
                digit=digit/10;
                digitcount++;
            }
            if(digitcount%2==0)
            {
                count++;
            }
        }
    return count;
    }
};