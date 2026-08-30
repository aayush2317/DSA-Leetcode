class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int> ans;
        vector<int> visited(n2,0);
        for(int i=0;i<n1;i++)
        {
            for(int j=0;j<n2;j++)
            {
                if(nums1[i]==nums2[j] && visited[j]==0)
                {
                    ans.push_back(nums1[i]);
                    visited[j]=1;
                    break;
                }
            }
        }
        return ans;
    }
};