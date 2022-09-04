#include <iostream>
#define INF 987654321
#define MAX 100002
using namespace std;

int N, K;
int memo[MAX];

int main() {
    cin >> N >> K;

    for (int i = 0; i < MAX; i++) {
        memo[i] = INF;
    }
    memo[0] = N;

    for (int i = 1; i < MAX; i++) {
        // N보다 작은 경우를 구하는 DP,
        if (i < N) {
            memo[i] = N - i;
        }
        // N보다 큰 경우를 구하는 DP.
        // n = k_1 + 1, n = k_2 - 1, n = k_3 * 2 => k1 = n-1, k2 = n+1, k3 = n/2
        else if (i == N) memo[i] = 0;
        else {
            if (i%2 == 0) {
                memo[i] = min(min(memo[i+1]+1, memo[i-1]+1), memo[i/2]);
            }
            else {
                memo[i] = min(memo[i+1]+1, memo[i-1]+1);
            }
        }
        int idx = i*2;
        while (idx < MAX) {
            memo[idx] = min(memo[idx], memo[i]);
            idx = idx*2;
        }
    }

    cout << memo[K];

    return 0;
}