class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int maxi=0;
        unordered_set<int> st;
        for(int i=0;i<s.length();i++)
        {
            while(st.count(s[i]))
            {
                st.erase(s[left]);
                left++;
            }
            st.insert(s[i]);
            maxi=max(maxi,i-left+1);

        }
        return maxi;
    }
};