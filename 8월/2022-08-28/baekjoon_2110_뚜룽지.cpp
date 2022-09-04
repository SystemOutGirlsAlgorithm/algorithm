#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int install(int dist, vector<int> house_pos) {
    int pre_install_pos = house_pos[0];
    int cnt = 1;
    for (int i = 1; i < house_pos.size(); i++) {
        if (house_pos[i] - pre_install_pos >= dist) {
            ++cnt;
            pre_install_pos = house_pos[i];
        }
    }
    return cnt;
}

int main() {
    int N, C;
    cin >> N >> C;
    vector<int> house_pos(N);
    
    for (int i = 0; i < N; i++) {
        cin >> house_pos[i];
    }

    sort(house_pos.begin(), house_pos.end());
    int left = 1, right = house_pos[N-1] - house_pos[0] + 1;

    while (left < right) {
        int mid = (left+right)/2;
        
        if (install(mid, house_pos) < C) {
            right = mid;
        }
        else {
            left = mid+1;
        }
    }

    cout << left-1;
    return 0;
}