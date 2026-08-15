class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int,int> mp;
        unordered_map<int,int> sp;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]] +=1;
        }
         for(int i=0;i<t.length();i++)
        {
            sp[t[i]] +=1;
        }
        if(s.length()!=t.length())
        {
            return false;
        }
        for(int i=0;i<s.length();i++)
        {
            if(mp[s[i]]!=sp[s[i]])
            {
                return false;
            }
        }
        return true;
    }
};