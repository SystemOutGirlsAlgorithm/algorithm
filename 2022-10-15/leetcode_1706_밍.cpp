class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> res;
        // 해당 공 위치의 좌우에 같은 숫자가 있으면 거기로 이동 후 내려가기까지 한 루프에 구현...
        for (int i = 0; i < grid[0].size(); i++) {
            int loc = i, point = grid[0][loc], row = 0;
            while (true) {
                if (point == -1 && loc > 0 && grid[row][loc - 1] == point) {
                    if (row + 1>= grid.size()) {
                        res.push_back(--loc);
                        break;
                    }
                    else {
                        point = grid[++row][--loc];
                    }
                }
                else if (point == 1 && loc < grid[0].size() - 1 && grid[row][loc + 1] == point) {
                    if (row + 1 >= grid.size()) {
                        res.push_back(++loc);
                        break;
                    }
                    else {
                        point = grid[++row][++loc];
                    }
                }
                else {
                    res.push_back(-1);
                    break;
                }
                
            }
        }
        return res;
    }
};