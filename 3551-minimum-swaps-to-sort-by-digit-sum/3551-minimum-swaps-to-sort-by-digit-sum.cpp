class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>> arr;
        for(int i=0;i<n;i++)
        {
            int sum=0;
            int re=nums[i];
            while(re>0)
            {
                int r=re%10;
                re=re/10;
                sum+=r;
            }
            arr.push_back({sum,nums[i]});
        }
        sort(arr.begin(),arr.end());
        int swaps=0;
        unordered_map<int,int> pos;
        for(int i=0;i<nums.size();i++)
        {
            pos[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++)
        {
            int target=arr[i].second;
            if(nums[i]==target)
            continue;
            int j=pos[target];
            pos[nums[i]]=j;
            swap(nums[i], nums[j]);
            pos[target]=i;
            swaps++;
        }
        return swaps;
    }
};