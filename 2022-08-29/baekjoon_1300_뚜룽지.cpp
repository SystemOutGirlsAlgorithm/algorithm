#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, k;
    cin >> N >> k;
    
    long long low = 1, high = k;
    while (low < high) {
        long long mid = (low+high)/2;
        long long cnt = 0;
        for (int i = 1; i <= N; i++) { // k를 만족하는 lower bound 찾는다. B[k=cnt] = low
            cnt += min(mid/i, (long long)N);
        }

        if (cnt >= k) {
            high = mid;
        }
        else {
            low = mid+1;
        }

    }

    cout << low;

    return 0;
}