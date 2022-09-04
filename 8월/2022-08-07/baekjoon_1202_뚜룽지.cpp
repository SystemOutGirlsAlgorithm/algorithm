#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, K;
vector<pair<int, int> > jl_info; // {무게, 가격}
vector<int> kn_info;

int main() {
    cin >> N >> K;
    int weight, price;
    for (int i = 0; i < N; i++) {
        cin >> weight >> price;
        jl_info.push_back(make_pair(weight, price));
    }
    for (int i = 0; i < K; i++) {
        cin >> weight;
        kn_info.push_back(weight);
    }
    sort(jl_info.begin(), jl_info.end());
    sort(kn_info.begin(), kn_info.end());

    int check_idx = 0;
    long long ans = 0;
    priority_queue<int> list;
    for (int i = 0; i < K; i++) {
        while (check_idx < N && kn_info[i] >= jl_info[check_idx].first) {
            list.push(jl_info[check_idx++].second);
        }

        if (!list.empty()) {
            ans += list.top();
            list.pop();
        }
    }

    cout << ans;
    return 0;
}