class Solution {
public:
    bool checkValidString(string s) {
        int low=0;
        int high=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                high++;
                low++;
            }
            else if(s[i]=='*')
            {
                low--;
                high++;
            }
            else
            {
                low--;
                high--;
            }
            if(low < 0)
                low = 0;

            if(high < 0)
                return false;
        }
        if(low == 0)
        return true;
        else
        return false;
    }
};