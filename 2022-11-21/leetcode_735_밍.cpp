class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s, s2;
        for (auto a: asteroids) {
            if (s.empty()) s.push(a);
            else {
                if ((s.top() > 0 && a > 0) || s.top() < 0 && a < 0) s.push(a);
                else {
                    while (!s.empty() && s.top() > 0 && s.top() < abs(a)) s.pop();
                    if (!s.empty() && s.top() > abs(a)) continue;
                    else if (!s.empty() && s.top() == abs(a)) s.pop();
                    else s.push(a);
                }
            }
        }
        
        vector<int> res(s.size());
        for (int i = res.size()-1; i >= 0; i--) {
            res[i] = s.top();
            s.pop();
        }
        return res;
    }
};