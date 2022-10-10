class Solution {
public:
    int num;
    
    void dfs(vector<vector<char>>& grid, int sr, int sc) {
        if (sr < 0 || sr >= grid.size() || sc < 0 || sc >= grid[sr].size())
            return;
        
        if (grid[sr][sc] == '1') {
            grid[sr][sc] = '0';
            dfs(grid, sr-1, sc);
            dfs(grid, sr+1, sc);
            dfs(grid, sr, sc-1);
            dfs(grid, sr, sc+1);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        num = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    num++;
                }
            }
        }
        return num;
    }
};