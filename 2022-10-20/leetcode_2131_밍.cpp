class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> m;
        int len = 0, odd = 0;
        
        for (auto str: words) {
            if (str[0] == str[1]) {
                if (m[str] > 0) {
                    m[str]--;
                    odd--;
                    len += 4;
                }
                else {
                    m[str]++;
                    odd++;
                }
            }
            else {
                string revstr = str;
                reverse(revstr.begin(), revstr.end());
                
                if (m[revstr] > 0) {
                    m[revstr]--;
                    len += 4;
                }
                else {
                    m[str]++;
                }
            }
        }
        
        if (odd)
            len += 2;
        
        return len;
    }
};