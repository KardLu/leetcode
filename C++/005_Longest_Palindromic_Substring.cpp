class Solution {
public:
    string longestPalindrome(string s) {
    	int length = s.size();
    	if (length < 0)
    	    return string();
    	if (length == 1)
    	    return s;
    	if (length == 2) 
    	    return (s[0] == s[1]) ? s : string();

        int T[1000][1000];
        memset(T, 0, sizeof(int) * 1000 * 1000);
        
        for (int len = 0; len < 2; len++) {
        	for (int i = 0; i < length - len; i++) {
        		if (len == 0)
	        		T[i][i + len] = 1;
	        	else
	        		T[i][i + len] = (s[i] == s[i + len]) ? 2 : 0;
        	}
        }

        for (int len = 2; len < length; len++) {
        	for (int i = 0; i < length - len; i++) {
        		if (s[i] == s[i + len] && T[i + 1][i + len - 1])
        			T[i][i + len] = 2 + T[i + 1][i + len - 1];
        		else
        			T[i][i + len] = 0;
        	}
        }

        int start = 0;
        int maxLen = 0;
        for (int i = 0; i < length; i++)
        	for (int j = 0; j < length; j++) {
        		if (maxLen < T[i][j]) {
        			maxLen = T[i][j];
        			start = i;
        		}
        	}

        string subStr = s.substr(start, maxLen);

        return subStr;
    }
};