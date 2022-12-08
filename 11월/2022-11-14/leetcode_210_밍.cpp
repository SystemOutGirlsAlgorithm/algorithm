class Solution {
public:
    vector<int> ans;
    void dfs(vector<vector<int>>& g, vector<int>& p, int index) {
        ans.push_back(index);
        p[index] = -1;
        for (auto i: g[index]) {
            if (--p[i] == 0) dfs(g, p, i);
        }
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> preq(numCourses);
        
        for (auto p: prerequisites) {
            g[p[1]].push_back(p[0]);
            preq[p[0]]++;
        }
        
        for (int i = 0; i < numCourses; i++) {
            if (preq[i] == 0) dfs(g, preq, i);
        }
        
        if (ans.size() == numCourses) return ans;
        else return {};
    }
};