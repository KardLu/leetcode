class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows < 1) return NULL;
        if (numRows == 1) return s;
        int size = s.size();
        string newStr;
        for (int row = 0; row < numRows; row ++) {
          for (int i = row; i < size; i += 2 * (numRows - 1)) {
                newStr += s[i];
                if (row != 0 && row != numRows - 1 ) {
                    if (i + 2 * (numRows - row - 1) < size)
                        newStr += s[i + 2 * (numRows - row - 1)];
                }
            }
        }
        return newStr;
    }
};