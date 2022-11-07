class Solution {
public:
    static bool compare(pair<string, int> &a, pair<string, int> &b) {
        if (a.second > b.second) {
            return true;
        } else if (a.second == b.second) {
            if (a.first < b.first) 
                return true;
            else
                return false;
        }
        else {
            return false;
        }
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> m;
        for (auto i: words)
            m[i]++;
        vector<pair<string, int>> v(m.begin(), m.end());
        sort(v.begin(), v.end(), compare);
        
        vector<string> res(k);
        for(int i = 0; i < k; i++) {
            res[i] = v[i].first;
        }
        return res;
    }
};