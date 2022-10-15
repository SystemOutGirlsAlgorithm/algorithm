class Solution {
public:
    bool isHappy(int n) {
        while (n > 9) {
            int temp = 0;
            string numstr = to_string(n);
            for (auto i: numstr) {
                temp += ((int)i - '0')*((int)i - '0');
            }
            n = temp;
        }
        
        if (n == 1 || n == 7)
            return true;
        else
            return false;
    }
};