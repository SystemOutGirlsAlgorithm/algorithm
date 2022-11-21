#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int board[500][500];

bool isRange(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int cnt1(int x, int y) {
    int res = 0;
    // i) -
    if (isRange(x, y+3))
        res = max(res, board[x][y]+board[x][y+1]+board[x][y+2]+board[x][y+3]);
    // ii) l
    if (isRange(x+3, y))
        res = max(res, board[x][y]+board[x+1][y]+board[x+2][y]+board[x+3][y]);
    return res;
}

int cnt2(int x, int y) {
    int res = 0;
    if (isRange(x+1, y+1))
        res = max(res, board[x][y] + board[x+1][y] + board[x+1][y+1] + board[x][y+1]);
    return res;
}

int cnt3(int x, int y) {
    int res = 0;
    // i) L - 오른쪽
    if (isRange(x+2, y+1))
        res = max(res, board[x][y]+board[x+1][y]+board[x+2][y]+board[x+2][y+1]);
    // ii) L - 왼쪽
    if (isRange(x+2, y-1))
        res = max(res, board[x][y]+board[x+1][y]+board[x+2][y]+board[x+2][y-1]);
    // iii) ㄱ - 왼쪽
    if (isRange(x+2, y+1))
        res = max(res, board[x][y]+board[x][y+1]+board[x+1][y+1]+board[x+2][y+1]);
    // iv) ㄱ - 오른쪽
    if (isRange(x, y+1) && isRange(x+2, y))
        res = max(res, board[x][y]+board[x+1][y]+board[x+2][y]+board[x][y+1]);
    // i) 낮은 L - 오른쪽
    if (isRange(x+1, y+2))
        res = max(res, board[x][y]+board[x+1][y]+board[x+1][y+1]+board[x+1][y+2]);
    // ii) 낮은 L - 왼쪽
    if (isRange(x-1, y+2))
        res = max(res, board[x][y]+board[x][y+1]+board[x][y+2]+board[x-1][y+2]);
    // iii) 낮은 ㄱ - 왼쪽
    if (isRange(x+1, y+2))
        res = max(res, board[x][y]+board[x][y+1]+board[x][y+2]+board[x+1][y+2]);
    // iv) 낮은 ㄱ - 오른쪽
    if (isRange(x+1, y) && isRange(x, y+2))
        res = max(res, board[x][y]+board[x][y+1]+board[x][y+2]+board[x+1][y]);
    return res;
}

int cnt4(int x, int y) {
    int res = 0;
    // i) l|
    if (isRange(x+2, y+1))
        res = max(res, board[x][y]+board[x+1][y]+board[x+1][y+1]+board[x+2][y+1]);
    // ii) |l
    if (isRange(x+2, y-1))
        res = max(res, board[x][y]+board[x+1][y]+board[x+1][y-1]+board[x+2][y-1]);
    // iii) -_
    if (isRange(x+1, y+2))
        res = max(res, board[x][y]+board[x][y+1]+board[x+1][y+1]+board[x+1][y+2]);
    // iv) _-
    if (isRange(x+1, y-2))
        res = max(res, board[x][y]+board[x][y-1]+board[x+1][y-1]+board[x+1][y-2]);
    return res;
}


int cnt5(int x, int y) {
    int res = 0;
    // i) 우
    if (isRange(x, y+2) && isRange(x+1, y+1))
        res = max(res, board[x][y]+board[x][y+2]+board[x][y+1]+board[x+1][y+1]);
    // ii) 오
    if (isRange(x, y+2) && isRange(x-1, y+1))
        res = max(res, board[x][y]+board[x][y+2]+board[x][y+1]+board[x-1][y+1]);
    // iii) 아
    if (isRange(x+2, y) && isRange(x+1, y+1))
        res = max(res, board[x][y]+board[x+2][y]+board[x+1][y]+board[x+1][y+1]);
    // iv) 어
    if (isRange(x+2, y) && isRange(x+1, y-1))
        res = max(res, board[x][y]+board[x+2][y]+board[x+1][y]+board[x+1][y-1]);
    return res;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    /* INPUT */
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> board[i][j];
        }
    }

    int max_cnt = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            max_cnt = max(max_cnt, max(cnt1(i, j), max(cnt2(i, j), max(cnt3(i, j), max(cnt4(i, j), cnt5(i, j))))));
        }
    }

    /* SOLUTION */
    cout << max_cnt;


    return 0;
}