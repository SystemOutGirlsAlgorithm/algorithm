class Solution {
public:
    string removeDuplicates(string s) {
        for (int i = 0; i < s.size() - 1; i++) {
            if (s == "") return s;
            
            if (s[i] == s[i + 1]) {
                s.erase(i, 2);
                
                if (i > 1) i -= 3;
                else i = -1;
            }
        }
        return s;
    }
};