#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int memory[101];
int cost[101];
int sum = 0;
int memo[101][10001];   // i번째 앱까지, j비용일 때 가능한 최대 메모리

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> memory[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> cost[i];
        sum += cost[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= sum; j++) {
            if (j - cost[i] >= 0) {
                memo[i][j] = max(memo[i][j], memo[i-1][j-cost[i]] + memory[i]);
            }
            memo[i][j] = max(memo[i][j], memo[i-1][j]);
        }
    }

    for (int i = 0; i <= sum; i++) {
        if (memo[N][i] >= M) {
            cout << i;
            break;
        }
    }

    return 0;
}