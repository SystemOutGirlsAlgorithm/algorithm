#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int K, N;
    cin >> K >> N;
    vector<int> list(K);
    
    long long low = 0, high;
    for (int i = 0; i < K; i++) {
        cin >> list[i];
        high = max(high, (long long)list[i]);
    }
    ++high;

    while (low < high) {
        long long mid = (low+high)/2;
        long long cnt = 0;
        for (int i = 0; i < K; i++) {
            cnt += list[i]/mid;
        }

        if (cnt < N) {
            high = mid;
        }
        else {
            low = mid+1;
        }
    }

    cout << low-1;

    return 0;
}