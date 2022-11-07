class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        vector<char> str;
        int ptr = 0, resptr = INT_MAX;
        string result = "";
        
        if (strs.size() < 2) return strs[0];
        
        for (auto i: strs[0])
            str.push_back(i);
        
        for (int i = 1; i < strs.size(); i++) {
            for (int j = 0; j < strs[i].size(); j++) {
                if (j < str.size() && str[j] == strs[i][j]) ptr++;
                else break;
            }
            if (resptr > ptr) resptr = ptr;
            ptr = 0;
        }
        
        for (int c = 0; c < resptr; c++) {
            result += str[c];
        }
        return result;
    }
};