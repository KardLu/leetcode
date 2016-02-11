class Solution {
public:
    int reverse(int x) {
        if (x == 0) return x;
        if (x == INT_MIN) return 0;
        list<int> digit;
        bool isNegative = false;
        if (x < 0) {
            isNegative = true;
            x =  -x;
        }
        while(x) {
            digit.push_back(x % 10);
            x = x / 10;
        }
        
        int rst = 0;
        while(digit.size()) {
            if (rst > INT_MAX / 10) return 0;
            rst = rst * 10 + digit.front();
            digit.erase(digit.begin());
        }
        if (isNegative) rst = -rst;
        return rst;
    }
};