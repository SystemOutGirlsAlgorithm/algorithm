#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<pair<int, pair<int, int> > > ver;
int parent[1001];

int find_parent(int node) {
    if (parent[node] != node) return find_parent(parent[node]);
    return node;
}

int main() {
    cin >> N >> M;
    int a, b, c;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        ver.push_back(make_pair(c, make_pair(a, b)));
    }
    sort(ver.begin(), ver.end());
    for (int i = 1; i < N; i++) {
        parent[i] = i;
    }

    int node1, node2, cost, n1_parent, n2_parent, ans = 0;
    for (int i = 0; i < ver.size(); i++) {
        node1 = ver[i].second.first;
        node2 = ver[i].second.second;
        cost = ver[i].first;
        n1_parent = find_parent(node1);
        n2_parent = find_parent(node2);
        if (n1_parent != n2_parent) {
            ans += cost;
            parent[n2_parent] = n1_parent;
        }
    }

    cout << ans;
    return 0;
}