class Solution {
public:
    vector<int> getRow(int rowIndex) {
        long long ans=1;
        vector<int> answer;
        if(ans==1)
        {
            answer.push_back(ans);
        }
        for(int i=0;i<rowIndex;i++)
        {
            ans=ans*(rowIndex-i);
            ans=ans/(i+1);
            answer.push_back(ans);
        }
        return answer;
    }
};