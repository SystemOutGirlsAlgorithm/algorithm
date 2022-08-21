#include <iostream>
using namespace std;

int isPrime[1000001];
int M, N;

int main() {
    cin >> M >> N;

    for (int i = 1; i < 1000001; ++i) {
        isPrime[i] = 1;
    }

    isPrime[1] = 0;
    
    for (int i = 2; i*i <= N; i++) {
        if (isPrime[i]) {
            for (int j = i*i; j <= N; j += i) {
                isPrime[j] = 0;
            }
        }
    }

    for (int i = M; i <= N; i++) {
        if (isPrime[i]) cout << i << " ";
    }

    return 0;
}