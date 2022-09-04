#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int V, E;
vector<pair<int, pair<int, int> > > ver;
int parent[10001];

int findParent(int node) {
    if (parent[node]!=node) return findParent(parent[node]);
    return node;
}

int main() {
    cin >> V >> E;
    int a, b, c;
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        ver.push_back(make_pair(c, make_pair(a, b)));
    }

    sort(ver.begin(), ver.end());

    for (int i = 1; i <= V; i++) {
        parent[i] = i;
    }
    int ans = 0;
    for (int i = 0; i < ver.size(); i++) {
        int node1 = ver[i].second.first;
        int node2 = ver[i].second.second;
        int cost = ver[i].first;
        int n1_parent = findParent(node1);
        int n2_parent = findParent(node2);
        if (n1_parent != n2_parent) {
            ans += cost;
            parent[n2_parent] = n1_parent;
        }
    }

    cout << ans;
    return 0;
}