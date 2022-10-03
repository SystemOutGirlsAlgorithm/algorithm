#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int board[18][18];
int dp[18][18][3];


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // INPUT
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
        }
    }

    dp[1][2][0] = 1;
    // SIMULATION
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i==1 && j<=2) continue;
            if (board[i][j]) continue;

            // 0 : x,y-1,2 || x,y-1,0
            //if (!board[i][j-1])
                dp[i][j][0] = dp[i][j-1][2] + dp[i][j-1][0];

            // 1 : x-1,y,1 || x-1,y,2
            //if (!board[i-1][j])
                dp[i][j][1] = dp[i-1][j][1] + dp[i-1][j][2];

            // 2 : x-1,y-1,0 || x-1,y-1,1 || x-1,y-2,2
            if (!board[i-1][j] && !board[i][j-1])
                dp[i][j][2] = dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2];
        }
    }

    cout << dp[N][N][0]+dp[N][N][1]+dp[N][N][2];
    
    return 0;
}