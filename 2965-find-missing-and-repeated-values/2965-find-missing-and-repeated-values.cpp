class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int total=n*n;
        vector<int> ans(total+1,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans[grid[i][j]]++;
            }
        }
        int repeating=-1;
        int missing=-1;
        for(int i=1;i<=total;i++)
        {
           if(ans[i]==2)
           {
            repeating=i;
           } 
           else if(ans[i]==0)
           {
            missing=i;
           }
        }
        return {repeating,missing};

    }
};