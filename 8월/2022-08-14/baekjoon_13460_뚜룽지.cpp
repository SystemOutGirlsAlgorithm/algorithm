#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


char board[10][10];
int N, M;
int step, ans = 987654321;
pair<int, int> ball[2];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int move_ball(int ball_num, int dir) {
    int nx = ball[ball_num].first; int ny = ball[ball_num].second;
    while (board[nx + dx[dir]][ny + dy[dir]] != '#') {
        nx = nx + dx[dir];
        ny = ny + dy[dir];
        if (board[nx][ny] == 'O') { // 탈출
            ball[ball_num].first = nx;
            ball[ball_num].second = ny;
            return -1;
        }
        
        if (nx == ball[(ball_num+1)%2].first && ny == ball[(ball_num+1)%2].second) {
            if (ball[ball_num].first == nx - dx[dir] && ball[ball_num].second == ny - dy[dir]) {
                return 0;
            }
            ball[ball_num].first = nx - dx[dir];
            ball[ball_num].second = ny - dy[dir];
            return 1;
        }
    }
    if (ball[ball_num].first == nx && ball[ball_num].second == ny) {
        return 0;
    }
    ball[ball_num].first = nx;
    ball[ball_num].second = ny;
    return 1;
}

int get_order(int dir) {    // 우선순위를 결정해준다.
    int rx = ball[0].first, ry = ball[0].second, bx = ball[1].first, by = ball[1].second;
    if (dx[dir]!=0) { // x가 움직임, y가 같은곳에 있는지 비교.
        if (ry == by) {
            // 만약 dx[dir] = 1이면, x가 큰것이 오더가 높음. 1 2 -> 2. 1 < 2
            // -1이면, x가 작은것이 오더가 높음. 1 2 -> 1. -1 > -2
            return dx[dir]*rx < dx[dir]*bx;
        }
        return 0;
    }
    else { // y가 움직임, x가 같은곳에 있는지 비교.
        if (rx == bx) {
            return dy[dir]*ry < dy[dir]*by;
        }
        return 0;
    }
}

void dfs(int step) {
    if (step > 10) return ;
    int red_ball_x = ball[0].first;
    int red_ball_y = ball[0].second;
    int blue_ball_x = ball[1].first;
    int blue_ball_y = ball[1].second;

    for (int dir = 0; dir < 4; dir++) {
        ball[0].first = red_ball_x;
        ball[0].second = red_ball_y;
        ball[1].first = blue_ball_x;
        ball[1].second = blue_ball_y;

        // 볼을 움직이고,
        int order = get_order(dir);
        int result[2];
        result[order] = move_ball(order, dir);
        result[(order+1)%2] = move_ball((order+1)%2, dir);
        //printf("[dfs%d] direction %d \n \tred_result is %d : (%d, %d)\n \tblue_result is %d : (%d, %d)\n", step, dir, result[0], ball[0].first, ball[0].second, result[1], ball[1].first, ball[1].second);

        // 결과 확인.
        // 둘 다 상태가 똑같다면.
        if (result[0] != 0 || result[1] != 0) {
            if ((result[0] == -1) || (result[1] == -1)) {
                if (result[1] != -1) {
                    ans = min(ans, step);
                }
            }
            else dfs(step+1);
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'R') {
                ball[0] = make_pair(i, j);
                board[i][j] = '.';
            }
            else if (board[i][j] == 'B') {
                ball[1] = make_pair(i, j);
                board[i][j] = '.';
            }
        }
    }
    /************************ INPUT ************************/


    dfs(1);
    if (ans == 987654321) cout << -1;
    else cout << ans;
    


}