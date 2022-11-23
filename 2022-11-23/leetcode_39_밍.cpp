class Solution {
public:
    vector<vector<int>> res;
    vector<int> interim;
    
    void sol(vector<int>& c, int i, int rem) {
        if (rem < 0 || i >= c.size()) return;
        else if (rem == 0) {
            res.push_back(interim);
        }
        else {
            sol(c, i + 1, rem);
            interim.push_back(c[i]);
            sol(c, i, rem - c[i]);
            interim.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sol(candidates, 0, target);
        return res;
    }
};