class Solution {
public:
    int ans = 0;
    vector<bool> visited;
    void dfs(vector<vector<int>> con, int i) {
        if (!visited[i]) {
            visited[i] = true;
            for (int idx = 0; idx < con[i].size(); idx++) {
                if (i == idx) continue;
                else if (con[i][idx] == 1) dfs(con, idx);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        for (int n = 0; n < isConnected.size(); n++) visited.push_back(false);
        for (int i = 0; i < isConnected.size(); i++) {
            if (!visited[i]) {
                ans++;
                dfs(isConnected, i);
            }
        }
        return ans;
    }
};