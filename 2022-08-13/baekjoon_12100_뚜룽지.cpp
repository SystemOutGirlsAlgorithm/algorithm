#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, maxx = 0;
int board[20][20];

vector<int> save[20];
vector<int> list[20];
int dx[2] = { 0, 1 }; // 위, 왼, 아래, 오
int dy[2] = { 1, 0 };


void initialVector() {
    for (int i = 0; i < N; i++) {
        save[i].clear();
        list[i].clear();
    }
}

void reposition(int direction) {    // 3.
    int x, y;

    if (direction == 0) {
        for (int i = 0; i < N; i++) { // dir 0
            for (int j = 0; j < N; j++) {
                if (list[j].size() > i) {
                    board[i][j] = list[j][i];
                    if (maxx < board[i][j]) maxx = board[i][j];
                }
                else {
                    board[i][j] = 0;
                }
            }
        }
    }
    else if (direction == 1) {
        for (int i = 0; i < N; i++) { // dir 1
            for (int j = 0; j < N; j++) {
                if (list[i].size() > j) {
                    board[i][j] = list[i][j];
                    if (maxx < board[i][j]) maxx = board[i][j];
                }
                else {
                    board[i][j] = 0;
                }
            }
        }
    }
    else if (direction == 2) {
        for (int i = N-1; i >= 0; i--) { // dir 2
            for (int j = N-1; j >= 0; j--) {
                if (list[j].size() > (N-i-1)) {
                    board[i][j] = list[j][N-i-1];
                    if (maxx < board[i][j]) maxx = board[i][j];
                }
                else {
                    board[i][j] = 0;
                }
            }
        }
    }
    else if (direction == 3) {
        for (int i = N-1; i >= 0; i--) { // dir 3
            for (int j = N-1; j >= 0; j--) {
                if (list[i].size() > (N-j-1)) {
                    board[i][j] = list[i][N-j-1];
                    if (maxx < board[i][j]) maxx = board[i][j];
                }
                else {
                    board[i][j] = 0;
                }
            }
        }
    }

}

void merge() {  // 2.
    for (int i = 0; i < N; i++) {
        int pre_num = -1;
        int top_idx = 0;
        while (top_idx < save[i].size()) {
            if (save[i][top_idx] == pre_num) {
                pre_num = -1;
                list[i].pop_back();
                list[i].push_back(save[i][top_idx++]*2);
            }
            else {
                pre_num = save[i][top_idx++];
                list[i].push_back(pre_num);
            }
        }
    }
}

void push(int direction) { // 1.
    int x, y;
    if (direction/2 == 0) {
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < N; y++) {
                if (board[x][y] != 0) save[x*dx[direction%2] + y*dy[direction%2]].push_back(board[x][y]);
            }
        }
    }
    else {
        for (int x = N-1; x >= 0; x--) {
            for (int y = N-1; y >= 0; y--) {
                if (board[x][y] != 0) save[x*dx[direction%2] + y*dy[direction%2]].push_back(board[x][y]);
            }
        }
    }
}

void find_max() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (maxx < board[i][j]) maxx = board[i][j];
        }
    }
}

void bt(int step) {
    if (step == 5) {
        return ;
    }

    int temp_board[20][20];
    copy(&board[0][0], &board[0][0]+400, &temp_board[0][0]);
    for (int i = 0; i < 4; i++) {
        initialVector();
        copy(&temp_board[0][0], &temp_board[0][0]+400, &board[0][0]);
        push(i);
        merge();
        reposition(i);
        bt(step+1);
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    bt(0);

    cout << maxx;
    return 0;
}