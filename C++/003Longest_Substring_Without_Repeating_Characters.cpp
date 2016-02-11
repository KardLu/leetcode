class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lenOfS = s.length();
        int *len = (int*)malloc(sizeof(int) * lenOfS);
        for (int i = 0; i < lenOfS; i++) {
            len[i] = 0;
        }
        len[0] = 1;
        for (int i = 1; i < lenOfS; i++) {
            len[i] = len[i-1] + 1;
            for (int j = len[i-1]; j > 0; j--) {
                if (s[i] == s[i-j]) {
                    len[i] = j;
                    break;
                }
            }
        }
        int max = 0;
        for (int i = 0; i < lenOfS; i++) {
            if (max < len[i])
                max = len[i];
        }
        
        //free len
        
        return max;
    }
};