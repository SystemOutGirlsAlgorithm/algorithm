class Solution {
private:
    queue<pair<int, int>> q;
    int fresh = 0;
    int ans = 0;
public:
    void push(vector<vector<int>>& grid, int i, int j) {
        cout << "i: " << i << " j: " << j << endl;
        grid[i][j] = 2;
        fresh--;
        q.push({i, j});
    }
    int orangesRotting(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) fresh++;
                else if (grid[i][j] == 2) q.push({i, j});
            }
        }
        
        if (!fresh && q.empty()) return 0;
        
        while (!q.empty()) {
            int size = q.size();
            while(size--) { // depth
                int i = q.front().first;
                int j = q.front().second;
                cout << "i: " << i << " j: " << j << endl;
                q.pop();
                
                if (i > 0 && grid[i-1][j] == 1) push(grid, i-1, j);
                if (i < grid.size() - 1 && grid[i+1][j] == 1) push(grid, i+1, j);
                if (j > 0 && grid[i][j-1] == 1) push(grid, i, j-1);
                if (j < grid[i].size() - 1 && grid[i][j+1] == 1) push(grid, i, j+1);
            }
            ans++;
        }
        
        if (fresh) return -1;
        else return ans - 1;
    }
};