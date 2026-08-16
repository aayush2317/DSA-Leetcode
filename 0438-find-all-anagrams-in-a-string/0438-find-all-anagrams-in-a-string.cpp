class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map<int,int> mp;
        unordered_map<int,int> sp;
        for(int i=0;i<p.length();i++)
        {
            mp[p[i]]++;
        }
        
        for(int i=0;i<p.length();i++)
        {
            sp[s[i]]++;
        }
        if(mp==sp)
        {
            ans.push_back(0);
        }
        for(int i = p.length(); i < s.length(); i++)
        {
            int removeChar = s[i - p.length()];
            
            sp[removeChar]--;

            if(sp[removeChar] == 0)
            {
                sp.erase(removeChar);
            }
            sp[s[i]]++;
            if(mp == sp)
            {
                ans.push_back(i - p.length() + 1);
            }
        }
        return ans;
        
    }
};