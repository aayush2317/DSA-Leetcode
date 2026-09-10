class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        vector<vector<int>> l(m+1, vector<int>(n+1, 0));

        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0 || j==0)
                {
                    l[i][j]=0;
                }
                else if(text1[i-1]==text2[j-1])
                {
                    l[i][j]=1+l[i-1][j-1];
                }
                else
                {
                    l[i][j]=max(l[i-1][j],l[i][j-1]);
                }
            }
        }
        return l[m][n];
    }
};