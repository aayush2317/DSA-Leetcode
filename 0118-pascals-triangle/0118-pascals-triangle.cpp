class Solution {
public:
vector<int> genRow(int row)
{
    vector<int> ansrow;
    ansrow.push_back(1);
    long long ans=1;
    for(int col=0;col<row;col++)
    {
        ans=ans*(row-col);
        ans=ans/(col+1);
        ansrow.push_back(ans);
    }
    return ansrow;
}
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> answer;
        for(int i=0;i<numRows;i++)
        {
            vector<int> temp=genRow(i);
            answer.push_back(temp);
        }
        return answer;
    }
};