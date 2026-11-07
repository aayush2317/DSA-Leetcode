class Solution {
public:
    int countAsterisks(string s) {
        int n=s.length();
        int ans=0;
        bool initially=false;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='|') initially=!initially;
            if(s[i]=='*' && initially==false)
            {
                ans++;
            }
        }
        return ans;
    }
};