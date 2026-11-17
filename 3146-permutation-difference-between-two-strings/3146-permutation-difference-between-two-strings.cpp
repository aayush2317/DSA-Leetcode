class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int n=s.size();
        int m=t.size();
        int diff=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(s[i]==t[j])
                {
                    diff+=abs(i-j);
                }
            }
        }
        return diff;
    }
};