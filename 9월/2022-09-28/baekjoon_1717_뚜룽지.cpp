#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int parent[1000001];

int find_parent(int node) {
    if (parent[node] == node) return node;
    else return parent[node] = find_parent(parent[node]);
}

bool is_union_(int a, int b) {
    int pa = find_parent(a);
    int pb = find_parent(b);
    return pa == pb;
}

void union_find(int a, int b) {
    int pa = find_parent(a);
    int pb = find_parent(b);

    if (pa != pb) {
        if (pa > pb)
            parent[pa] = pb;
        else 
            parent[pb] = pa;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;

    for (int i = 0; i <= n; ++i) {
        parent[i] = i;
    }

    int logic, a, b;
    for (int i = 0; i < m; ++i) {
        cin >> logic >> a >> b;
        if (logic) { // 1 : 포함 확인
            if (is_union_(a, b)) cout << "YES\n";
            else cout << "NO\n";
        }
        else { // 0 : 합치기
            union_find(a, b);
        }
    }

    return 0;
}