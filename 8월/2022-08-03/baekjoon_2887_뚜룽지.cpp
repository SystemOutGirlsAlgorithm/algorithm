#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int parent[100000];
vector<pair<int, int> > X;
vector<pair<int, int> > Y;
vector<pair<int, int> > Z;
vector<pair<int, pair<int, int> > > ver; // cost, node1, node2

int find_parent(int node) {
    if (parent[node] != node) return parent[node] = find_parent(parent[node]);
    return node;
}

int main() {
    cin >> N;
    int a, b, c;
    for (int i = 0; i < N; i++) {
        cin >> a >> b >> c;
        X.push_back(make_pair(a, i));
        Y.push_back(make_pair(b, i));
        Z.push_back(make_pair(c, i));
        parent[i] = i;
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    sort(Z.begin(), Z.end());

    for (int i = 0; i < N-1; i++) {
        ver.push_back(make_pair(X[i+1].first - X[i].first, make_pair(X[i].second, X[i+1].second)));
        ver.push_back(make_pair(Y[i+1].first - Y[i].first, make_pair(Y[i].second, Y[i+1].second)));
        ver.push_back(make_pair(Z[i+1].first - Z[i].first, make_pair(Z[i].second, Z[i+1].second)));
    }
    sort(ver.begin(), ver.end());

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