class Solution {
     int findmaxindex(vector<vector<int>>& mat,int n,int m, int col)
    {
        int maxvalue=-1;
        int index=-1;
        for(int i=0;i<n;i++)
        {
            if(mat[i][col]>maxvalue)
            {
                maxvalue=mat[i][col];
                index=i;
            }
        }
        return index;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0;
        int high=m-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int maxrowindex=findmaxindex(mat,n,m,mid);
            int left=mid-1>=0 ? mat[maxrowindex][mid-1]:-1;
            int right=mid+1<m ? mat[maxrowindex][mid+1]:-1;
            if(mat[maxrowindex][mid]>left && mat[maxrowindex][mid]>right)
            {
                return {maxrowindex,mid};
            }
            else if(mat[maxrowindex][mid]<left)
            {
                high=mid-1;
            }
            else low=mid+1;
        }
        return {-1,-1};
    }
};