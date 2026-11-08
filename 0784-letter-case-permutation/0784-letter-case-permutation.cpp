
class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans = {""};

        for(int i = 0; i < s.size(); i++)
        {
            if(isdigit(s[i]))
            {
                for(int j = 0; j < ans.size(); j++)
                {
                    ans[j].push_back(s[i]);
                }
                continue;
            }
            else
            {
                vector<string> temp;

                for(int j = 0; j < ans.size(); j++)
                {
                    string str = ans[j];

                    temp.push_back(str + (char)tolower(s[i]));
                    temp.push_back(str + (char)toupper(s[i]));
                }

                ans = temp;
            }
        }

        return ans;
    }
};
