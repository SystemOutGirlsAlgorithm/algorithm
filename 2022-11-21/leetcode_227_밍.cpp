class Solution {
public:
    int calculate(string s) {
        int ans = 0, temp = 0;
        s += "###";
        char prev = '+';
        stack<int> stk;
        
        for (auto c: s) {
            if (isspace(c)) continue;
            else if (isdigit(c)) temp = (temp*10) + (c - '0');
            else {
                if (prev == '+') stk.push(temp);
                else if (prev == '-') stk.push(-temp);
                else if (prev == '*') {
                    temp = stk.top() * temp;
                    stk.pop();
                    stk.push(temp);
                }
                else if (prev == '/') {
                    temp = stk.top() / temp;
                    stk.pop();
                    stk.push(temp);
                }
                prev = c;
                temp = 0;
            }
        }
        
        int res = 0;
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};