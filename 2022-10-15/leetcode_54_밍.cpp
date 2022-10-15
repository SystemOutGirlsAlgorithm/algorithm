class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rowstart = 0, colstart = 0, rowend = matrix.size() - 1, colend = matrix[0].size() - 1;
        vector<int> res;
        vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));
        
        if (rowend == 0 && colend == 0) res.push_back(matrix[0][0]);
        else {
            while (rowstart <= rowend && colstart <= colend) {
                for (int c = colstart; c < colend && !visited[rowstart][c]; c++) {
                    res.push_back(matrix[rowstart][c]);
                    visited[rowstart][c] == true;
                }
                    
                for (int r = rowstart; r < rowend && !visited[r][colend]; r++) {
                    res.push_back(matrix[r][colend]);
                    visited[r][colend] = true;
                }
                    
                if (rowend - rowstart == 0 || colend - colstart == 0 && !visited[rowend][colend]) {
                    res.push_back(matrix[rowend][colend]);
                    break; // break if the matrix has 1 row or 1 col
                }
                
                for (int c = colend; c > colstart && !visited[rowend][c]; c--) {
                    res.push_back(matrix[rowend][c]);
                    visited[rowend][c] = true;
                }
                for (int r = rowend; r > rowstart && !visited[r][colstart]; r--) {
                    res.push_back(matrix[r][colstart]);
                    visited[r][colstart] = true;
                }
                
                if (rowstart == rowend && colstart == colend && !visited[rowstart][colstart]) {
                    res.push_back(matrix[rowstart][colstart]);
                    break;
                }
                rowstart++; colstart++; rowend--; colend--;
            }
        }
        return res;
    }
};