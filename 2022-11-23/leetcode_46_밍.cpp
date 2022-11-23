class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    map<int, bool> visited;
    void permutation(vector<int>& nums) {
        if (tmp.size() >= nums.size()) {
            res.push_back(tmp);
        }
        else {
            for (auto n: nums) {
                if (!visited[n]) {
                    tmp.push_back(n);
                    visited[n] = true;
                    permutation(nums);
                    tmp.pop_back();
                    visited[n] = false;
                }
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        permutation(nums);
        return res;
    }
};