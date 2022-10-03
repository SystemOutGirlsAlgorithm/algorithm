class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> m;
        set<char> bdup;
        for (int idx = 0; idx < s.size(); idx++) {
            if (m.find(s[idx]) == m.end()) {
                if (m.insert({s[idx], t[idx]}).second && !bdup.insert(t[idx]).second)
                    return false;
            }
            else if (m[s[idx]] != t[idx]) {
                return false;
            }
        }
        return true;
    }
};