class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx = 0;
        for (auto i: t) {
            if (i == s[idx])
                idx++;
        }
        
        if (idx != s.size())
            return false;
        else
            return true;
    }
};