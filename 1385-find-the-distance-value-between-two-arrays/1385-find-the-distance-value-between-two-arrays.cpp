class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n=arr1.size();
        int m=arr2.size();
        int dis=0;
        for(int i=0;i<n;i++)
        {
            bool valid=true;
            for(int j=0;j<m;j++)
            {
                int diff=abs(arr1[i]-arr2[j]);
                if(diff<=d)
                {
                    valid=false;
                    break;
                }
            }
            if(valid==true) dis++;
        }
        return dis;
    }
};