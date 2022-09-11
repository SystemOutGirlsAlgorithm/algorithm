#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
using namespace std;

vector<pair<int, int> > ver[20001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int V, E, K;
    cin >> V >> E >> K;

    int a, b, l;
    for (int i = 0; i < E; ++i) {
        cin >> a >> b >> l;
        ver[a].push_back(make_pair(b, l));
    }

    priority_queue<pair<int, int> > que; // 내림차순 정렬됨.
    vector<int> dist(V+1, INF);
    dist[K] = 0;
    que.push(make_pair(0, K));

    while (!que.empty()) {
        int top_node = que.top().second;
        int top_dist = -que.top().first;
        que.pop();

        for (int i = 0; i < ver[top_node].size(); ++i) {
            pair<int, int> new_ = ver[top_node][i];
            int new_node = new_.first;
            int new_dist = new_.second + top_dist;

            if (dist[new_node] > new_dist) {
                dist[new_node] = new_dist;
                que.push(make_pair(-new_dist, new_node)); // 내림차순 정렬이므로, cost를 음수로 만들어 넣어 (원래는) 작은 값을 top에 오도록 한다.
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        int distance = dist[i];
        if (distance == INF) cout << "INF\n";
        else cout << distance << "\n";
    }

    return 0;
}