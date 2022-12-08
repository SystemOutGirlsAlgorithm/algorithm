class Solution {
public:
    bool flag = false;
    void dfs(vector<vector<char>>& b, vector<vector<bool>>& v, string w, int i, int j, int d) {
        if (i < 0 || i >= b.size() || j < 0 || j >= b[0].size()) return;
        if (!v[i][j] && w[d] == b[i][j] && d == w.size() - 1) {
            v[i][j] = true;
            flag = true;
        }
        else if (!v[i][j] && w[d] == b[i][j]) {
            v[i][j] = true;
            dfs(b, v, w, i+1, j, d+1);
            dfs(b, v, w, i-1, j, d+1);
            dfs(b, v, w, i, j+1, d+1);
            dfs(b, v, w, i, j-1, d+1);
            if (!flag) v[i][j] = false;
        }
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0]) {
                    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
                    dfs(board, visited, word, i, j, 0);
                    if (flag) return true;
                }
            }
        }
        return false;
    }
};