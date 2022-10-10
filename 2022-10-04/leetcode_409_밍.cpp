class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> m;
        for (auto i: s) {
            if (m[i])
                m[i]++;
            else
                m[i] = 1;
        }
        
        int len = 0;
        bool flag = false;
        for (int i = 65; i <= 122; i++) {
            if (m[char(i)]) {
                if (m[char(i)] % 2 == 0) {
                    len += m[char(i)];
                }
                else {
                    len += (m[char(i)] - 1);
                    flag = true;
                }
            }
        }
        
        if (flag) 
            return len + 1;
        else
            return len;
    }
};