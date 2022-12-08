#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
vector<int> ver[100001];
int parents[100001][20];
int depth[100001];
bool visited[100001];

int lca(int a, int b) {
    if (depth[a] > depth[b]) swap(a, b);

    int diff = depth[b] - depth[a];
    int x = 0;
    while (diff) {
        if (diff%2) {
            b = parents[b][x];
        }
        x++;
        diff /= 2;
    }

    while (a != b) {
        for (int i = 0; i < 20; ++i) {
            if (parents[a][i+1] == parents[b][i+1]) {
                a = parents[a][i];
                b = parents[b][i];
                break;
            }
        }
    }

    return a;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a, b;
    cin >> N;
    for (int i = 0; i < N-1; ++i) {
        cin >> a >> b;
        ver[a].push_back(b);
        ver[b].push_back(a);
    }

    visited[1] = true;
    queue<int> que;
    que.push(1);
    while (!que.empty()) {
        int top = que.front();
        que.pop();

        for (int i = 0; i < ver[top].size(); ++i) {
            int temp = ver[top][i];
            if (!visited[temp]) {
                parents[temp][0] = top;
                visited[temp] = true;
                depth[temp] = depth[top] + 1;

                for (int j = 0; j < 20; ++j) {
                    parents[temp][j+1] = parents[parents[temp][j]][j];

                    if (parents[temp][j+1] == 0) break;
                }

                que.push(temp);
            }
        }
    }


    cin >> M;
    for (int i = 0; i < M; ++i) {
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }

    return 0;
}