#include <iostream>
#include <vector>
using namespace std;

char board[10][10];
int D = 0;
int check_r[10][10];    // row, num
int check_c[10][10];    // col, num
int check_s[10][10];    // sub, num
vector<pair<int, int> > list;

void print() {
    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }
}

int check(int x, int y, int num) {
    return check_r[x][num] || check_c[y][num] || check_s[((x-1)/3)*3 + ((y-1)/3) + 1][num];
}

void mark_in(int i, int j) {
    check_r[i][board[i][j]-'0'] = 1;
    check_c[j][board[i][j]-'0'] = 1;
    check_s[((i-1)/3)*3 + ((j-1)/3) + 1][board[i][j]-'0'] = 1;
}

void mark_out(int i, int j) {
    check_r[i][board[i][j]-'0'] = 0;
    check_c[j][board[i][j]-'0'] = 0;
    check_s[((i-1)/3)*3 + ((j-1)/3) + 1][board[i][j]-'0'] = 0;
}

void dfs(int depth) {
    if (D <= depth) {
        print();
        exit(0);
    }
    int x = list[depth].first;
    int y = list[depth].second;
    for (int i = 1; i < 10; i++) {
        if (!check(x, y, i)) {
            board[x][y] = '0' + i;
            mark_in(x, y);
            dfs(depth+1);
            mark_out(x, y);
            board[x][y] = '0';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            cin >> board[i][j];
            if (board[i][j] != '0') {
                check_r[i][board[i][j]-'0'] = 1;
                check_c[j][board[i][j]-'0'] = 1;
                check_s[((i-1)/3)*3 + ((j-1)/3) + 1][board[i][j]-'0'] = 1;
            }
            else {
                list.push_back(make_pair(i, j));
            }
        }
    }
    D = list.size();
    dfs(0);
    return 0;
}