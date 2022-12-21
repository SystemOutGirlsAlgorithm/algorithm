class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, int> m;
        int size = dislikes.size();
        if (n == 1 || dislikes.size() == 0) return true;
        bool f = true;
        vector<int> tmp(2, 0);
        for (int i = 0; i < dislikes.size(); i++) {
            vector<int> d = dislikes[i];
            if (f) {
                m[d[0]] = 1;
                m[d[1]] = 2;
                f = false;
            }
            else {
                if (m.find(d[0]) == m.end() && m.find(d[1]) == m.end()) {
                    if (tmp[0] == 0) tmp = d;
                    else if (tmp == d){
                        m[d[0]] = 1;
                        m[d[1]] = 2;
                        tmp[0] = tmp[1] = 0;
                        continue;
                    }
                    vector<int> tmp2 = d;
                    dislikes.push_back(tmp2);
                }
                else if (m.find(d[0]) == m.end() && m.find(d[1]) != m.end())
                    m[d[0]] = (m[d[1]] == 1) ? 2 : 1;
                else if (m.find(d[0]) != m.end() && m.find(d[1]) == m.end())
                    m[d[1]] = (m[d[0]] == 1) ? 2 : 1;
                else if (m[d[0]] == m[d[1]]) return false;
            }
        }
        return true;
    }
};