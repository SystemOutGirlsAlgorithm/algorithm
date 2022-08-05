#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<int> connect[32001];
int in_ver[32001];

int main() {
    cin >> N >> M;
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        connect[a].push_back(b);
        ++in_ver[b];
    }

    queue<int> que;
    for (int i = 1; i <= N; i++) {
        if (in_ver[i] == 0) {
            que.push(i);
        }
    }

    while (!que.empty()) {
        int node = que.front();
        que.pop();
        cout << node << " ";
        for (int i = 0; i < connect[node].size(); i++) {
            if (--in_ver[connect[node][i]] == 0) {
                que.push(connect[node][i]);
            }
        }
    }

    return 0;
}