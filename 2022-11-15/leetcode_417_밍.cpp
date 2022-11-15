class Solution {
public:
    void dfs(vector<vector<int>>& h, vector<vector<bool>>& v, int i, int j) {
        if (i < 0 || j < 0 || i >= h.size() || j >= h[i].size()) return;
        
        if (!v[i][j]) {
            v[i][j] = true;
            if (i > 0 && h[i-1][j] >= h[i][j]) dfs(h, v, i-1, j); // up
            if (j > 0 && h[i][j-1] >= h[i][j]) dfs(h, v, i, j-1); // left
            if (i < h.size()-1 && h[i+1][j] >= h[i][j]) dfs(h, v, i+1, j); // down
            if (j < h[i].size()-1 && h[i][j+1] >= h[i][j]) dfs(h, v, i, j+1); // right
            
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        vector<vector<bool>> pac(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>> atl(heights.size(), vector<bool>(heights[0].size(), false));
        
        for (int i = 0; i < heights.size(); i++) {
            if (i == 0) {
                for (int j = 0; j < heights[i].size(); j++) dfs(heights, pac, i, j);
            }
            else {
                dfs(heights, pac, i, 0);
            }
        }
        
        for (int i = 0; i < heights.size(); i++) {
            if (i == heights.size() - 1) {
                for (int j = 0; j < heights[i].size(); j++) dfs(heights, atl, i, j);
            }
            else {
                dfs(heights, atl, i, heights[i].size() - 1);
            }
        }
        
        for (int i = 0; i < heights.size(); i++) {
            for (int j = 0; j < heights[i].size(); j++) {
                if (pac[i][j] && atl[i][j])
                    ans.push_back({i, j});
            }
        }
        return ans;
    }
};