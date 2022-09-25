#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int board[9][9];
vector<pair<int, int> > empty_space;

void print_sudoku() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

bool ispromising(int x, int y, int num) {
    for (int i = 0; i < 9; i++) {
        if (board[x][i] == num)
            return false;
    }

    for (int i = 0; i < 9; i++) {
        if (board[i][y] == num)
            return false;
    }

    int ni = (x/3)*3;
    int nj = (y/3)*3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; ++j) {
            if (board[i+ni][j+nj] == num)
                return false;
        }
    }

    return true;
}

void dfs(int idx) {
    if (idx == empty_space.size()) {
        print_sudoku();
        exit(0);
    }

    int x = empty_space[idx].first;
    int y = empty_space[idx].second;
    for (int i = 1; i <= 9; i++) {
        if (ispromising(x, y, i)) {
            board[x][y] = i;
            dfs(idx+1);
            board[x][y] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0) {
                empty_space.push_back(make_pair(i, j));
            }
        }
    }

    dfs(0);

    return 0;
}