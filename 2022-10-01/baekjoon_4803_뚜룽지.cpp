#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
int parent[501];
vector<int> ver[501]; // ver[a] = b -> (a->b)
bool visiting[501];

bool dfs(int node, int pre) {
    visiting[node] = true;

    for (int i = 0; i < ver[node].size(); ++i) {
        int nxt = ver[node][i];
        if (nxt == pre) continue;
        if (visiting[nxt]) return false;
        if (!dfs(nxt, node)) return false;
    }

    return true;
}

void init() {
    memset(visiting, false, sizeof(visiting));
    for (int i = 0; i <= n; ++i) ver[i].clear();
}

int main() {
    // sol1 : 위상정렬, union-find 사용... 이게 사이클이 있는 트리인지 아니면 각자 떨어진 트리인지 확인X.
    // sol2 : DFS -> (어디서부터? 임의의 점부터 시작 - 어디까지? 더 이상 연결된, 갈 수 있는 선이 없어질때 까지)
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    int cnt = 0;
    while (n != 0 || m != 0) {
        int a, b;
        init();
        for (int i = 0; i < m; ++i) {
            cin >> a >> b;
            ver[a].push_back(b);
            ver[b].push_back(a);
        }
        
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (!visiting[i] && dfs(i, 0)) ++ans;
        }

        cout << "Case " << ++cnt;
        if (ans == 0) cout << ": No trees.\n";
        else if (ans == 1) cout << ": There is one tree.\n";
        else cout << ": A forest of " << ans << " trees.\n";
        cin >> n >> m;
    }

    return 0;
}