#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    vector<vector<int>> m(rows);
    for (int i = 0, num = 1; i < m.size(); i++) {
        for (int j = 0; j < columns; j++) {
            m[i].push_back(num);
            num++;
        }
    }
    
    for (auto i: queries) {
        int min = rows * columns, x1 = i[0]-1, y1 = i[1]-1, x2 = i[2]-1, y2 = i[3]-1;
        
        // 시계방향은 row부터 증가
        for (int r = x1; r < x2; r++) {
            swap(m[r][y1], m[r+1][y1]);
        }
        
        // 아래쪽 col 증가
        for (int c = y1; c < y2; c++) {
            swap(m[x2][c], m[x2][c+1]);
        }

        // row 감소
        for (int r = x2; r > x1; r--) {
            swap(m[r][y2], m[r-1][y2]);
        }
        
        // col 감소
        for (int c = y2; c > y1 + 1; c--) {
            swap(m[x1][c], m[x1][c-1]);
        }    
        
        // 최소값 찾기
        vector<int> values;
        for (int a = x1; a <= x2; a++) {
            for (int b = y1; b <= y2; b++) {
                if (a == x1 || a == x2 || b == y1 || b == y2)
                    values.push_back(m[a][b]);
            }
        }
        sort(values.begin(), values.end());
        answer.push_back(values[0]);
    }
    
    return answer;
}