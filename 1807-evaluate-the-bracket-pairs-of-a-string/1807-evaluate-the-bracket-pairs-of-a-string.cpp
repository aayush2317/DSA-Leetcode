class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> st;
        int n=s.length();
        for(int i=0;i<knowledge.size();i++)
        {
            st[knowledge[i][0]]=knowledge[i][1];
        }
        string ans;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                string key="";
                i++;
                while(s[i]!=')')
                {
                    key+=s[i];
                    i++;
                }
                if(st.count(key))
                {
                    ans+=st[key];
                }
                else
                {
                    ans+="?";
                }
            }
            else
            {
                ans+=s[i];
            }
        }
        return ans;

    }
};