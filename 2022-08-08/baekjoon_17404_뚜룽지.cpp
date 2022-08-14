#include <iostream>
#include <algorithm>
using namespace std;

int N, ans = 987654321;
int cost[1000][3];
int memo[1000][3];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    for (int zerocolor = 0; zerocolor < 3; zerocolor++) {
        memo[0][zerocolor] = cost[0][zerocolor];
        for (int i = 1; i < 3; i++) {
            memo[0][(zerocolor+i)%3] = 1000001;
        }

        for (int i = 1; i < N-1; i++) {
            for (int color = 0; color < 3; color++) {
                memo[i][color] = cost[i][color] + min(memo[i-1][(color+1)%3], memo[i-1][(color+2)%3]);
            }
        }
        
        for (int i = 1; i < 3; i++) {
            memo[N-1][(zerocolor+i)%3] = cost[N-1][(zerocolor+i)%3] + min(memo[N-2][(zerocolor+i+1)%3], memo[N-2][(zerocolor+i+2)%3]);
            ans = min(ans, memo[N-1][(zerocolor+i)%3]);
        }
    }
     // i) N-2번째 집이 컬러0이 아님. ii) 0번째 집이 color0이 아님 -> 1번째 집은 color1 또는 color2.

     printf("%d", ans);
     return 0;
}