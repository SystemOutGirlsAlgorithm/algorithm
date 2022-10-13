class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> ss, ts;
        for (auto i: s) {
            if (i == '#') {
                if (!ss.empty())
                    ss.pop();
                else
                    continue;
            } else
                ss.push(i);
        }
        
        for (auto i: t) {
            if (i == '#') {
                if (!ts.empty())
                    ts.pop();
                else 
                    continue;
            } else
                ts.push(i);
        }
        
        if (ss == ts)
            return true;
        else
            return false;
    }
};