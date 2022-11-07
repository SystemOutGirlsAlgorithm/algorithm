class Solution {
public:
    int idx = 0;
    
    string decodeString(string &s) {
        string num = "", res = "";
        while (idx < s.size() && s[idx] != ']') {
            while (idx < s.size() && isalpha(s[idx])) res += s[idx++];
            
            if (idx >= s.size() || s[idx] == ']') continue;
            
            num = "";
            while (idx < s.size() && isdigit(s[idx])) num += s[idx++];  
            
            idx++;
            string tmp = decodeString(s);
            int mul = stoi(num);
            string multmp = "";
            for (int i = 0; i < mul; i++) multmp += tmp;
            res += multmp;
            idx++;
        }
        return res;
    }
};