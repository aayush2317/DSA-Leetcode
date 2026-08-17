class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp;
        unordered_map<char,char> sp;
        for(int i=0;i<s.length();i++)
        {
            if(mp.count(s[i]) && mp[s[i]]!=t[i])
            {
                return false;
            }
            if(sp.count(t[i]) && sp[t[i]]!=s[i])
            {
                return false;
            }
            mp[s[i]]=t[i];
            sp[t[i]]=s[i];
        }
        return true;
    }
};