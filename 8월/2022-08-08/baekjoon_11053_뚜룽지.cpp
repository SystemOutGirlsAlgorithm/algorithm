#include <iostream>
#define INF 987654321
using namespace std;

int N, ans = 1;
int arr[1000];
int memo[1000];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    memo[0] = 1;
    for (int i = 1; i < N; i++) {
        memo[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                memo[i] = max(memo[i], memo[j]+1);
            }
        }
        ans = max(ans, memo[i]);
    }

    cout << ans;
    return 0;
}