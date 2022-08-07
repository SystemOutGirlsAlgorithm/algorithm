#include <iostream>
#include <algorithm>
using namespace std;
#define INF 987654321

int N;
int matrix_info[501][2];
int memo[501][501];

int main() {
    cin >> N;
    int r, c;
    for (int i = 1; i <= N; i++) {
        cin >> r >> c;
        matrix_info[i][0] = r;
        matrix_info[i][1] = c;
    }

    for (int n = 1; n < N; n++) {   // 1. 몇개의
        for (int s = 1; s+n <= N; s++) {    // 2. 시작지점
            memo[s][s+n] = INF;
            for (int p = s; p <= s+n; p++) {    // 3. pivot
                memo[s][s+n] = min(memo[s][s+n], memo[s][p] + memo[p+1][s+n] + matrix_info[s][0]*matrix_info[p][1]*matrix_info[s+n][1]);
            }
        }
    }

    cout << memo[1][N];
}