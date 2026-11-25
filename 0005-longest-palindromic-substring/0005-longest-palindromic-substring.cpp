
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxLength = 0;
        int start = 0;

        for(int i = 0; i < n; i++) {

            int left = i;
            int right = i;

            while(left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }

            int length = right - left - 1;

            if(length > maxLength) {
                maxLength = length;
                start = left + 1;
            }

          
            left = i;
            right = i + 1;

            while(left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }

            length = right - left - 1;

            if(length > maxLength) {
                maxLength = length;
                start = left + 1;
            }
        }

        return s.substr(start, maxLength);
    }
};
