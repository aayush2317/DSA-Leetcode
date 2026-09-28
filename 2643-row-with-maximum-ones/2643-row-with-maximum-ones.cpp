class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int index=-1;
        int maxcount=-1;
        for(int i=0;i<mat.size();i++)
        {
            int cntrow=0;
            for(int j=0;j<mat[i].size();j++)
            {
                cntrow+=mat[i][j];

            }
            if(cntrow>maxcount)
            {
                maxcount=cntrow;
                index=i;
            }
        }
        return {index,maxcount};
    }
};