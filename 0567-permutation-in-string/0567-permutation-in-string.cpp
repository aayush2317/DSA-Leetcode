class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int hash1[26]={0};
        int hash2[26]={0};
        if(s1.size()>s2.size()) return false;
        for(int i=0;i<s1.size();i++)
        {
            hash1[s1[i]-'a']++;
        }
        for(int i=0;i<s1.size();i++)
        {
            hash2[s2[i]-'a']++;
        }
         if(equal(hash1, hash1 + 26, hash2))
            return true;
        for(int i=s1.size();i<s2.size();i++)
        {
            hash2[s2[i-s1.size()]-'a']--;
            hash2[s2[i]-'a']++;
             if(equal(hash1, hash1 + 26, hash2))
            return true;
        }
        return false;
    }
};