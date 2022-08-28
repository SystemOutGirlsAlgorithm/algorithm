#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int N, M;
    cin >> N;
    unordered_map<int, int> N_num;
    int temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        ++N_num[temp];
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> temp;
        cout << N_num[temp] << " ";
    }
    return 0;
}