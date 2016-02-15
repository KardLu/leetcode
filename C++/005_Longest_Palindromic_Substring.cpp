class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int maxLen = 0;
        int index = 0;
        
        for (int i = 1; i < s.size(); i++) {
            if (s[i] != s[i - 1]) {
                int l = start;
                int r = i - 1;
                while (l > 0 && r < s.size() - 1) {
                    if (s[l - 1] != s[r + 1]) {
                        break;
                    }else{
                        l--;
                        r++;
                    }
                }
                if (maxLen < r - l + 1) {
                    index = l;
                    maxLen = r - l + 1;
                }
                start = i;
            }
        }
        if (s.size() - start > maxLen) {
            return s.substr(start, s.size() - start);
        }
        
        return s.substr(index, maxLen);
    }
};