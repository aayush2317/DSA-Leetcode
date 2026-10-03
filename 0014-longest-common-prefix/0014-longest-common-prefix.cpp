class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string ans="";
        for(int j=0;j<strs[0].size();j++)
        {
            for(int i=1;i<n;i++)
            {
                if(j >= strs[i].size() || strs[i][j]!=strs[0][j])
                {
                    return ans;
                }
            }
            ans += strs[0][j];
        }
        if(ans=="")
        {
            return ans;
        }
        return ans;
    }
};