#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<int> time(N);
    for (int i = 0; i < N; i++) {
        cin >> time[i];
    }
    sort(time.begin(), time.end());

    long long low = 0, high = (long long)time[N-1]*M;    

    while (low < high) {
        long long mid = (low+high)/2;
        long long remain_people = M;
        
        for (int i = 0; i < N; i++) {
            remain_people -= mid/time[i];
            if (remain_people <= 0) break;
        }

        if (remain_people <= 0) { // 시간을 더 줄여야함...
            high = mid;
        }
        else {  // 시간을 더 늘리는 경우
            low = mid+1;
        }
    }

    cout << low;

    return 0;
}