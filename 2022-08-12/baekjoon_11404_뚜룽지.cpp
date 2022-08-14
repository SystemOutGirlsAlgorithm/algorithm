#include <iostream>
using namespace std;

int n, m;
int dist[101][101];

void floyd(int middle) {
    for (int i = 1; i <= n; i++) {
        if (i != middle) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][middle] == -1 || dist[middle][j] == -1) continue;
                if (dist[i][j] == -1) {
                    dist[i][j] = dist[i][middle] + dist[middle][j];
                }
                else {
                    dist[i][j] =  min(dist[i][j], dist[i][middle] + dist[middle][j]);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    int cost, a, b;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i!=j) dist[i][j] = -1;
        }
    }

    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> cost;
        if (dist[a][b] != -1) dist[a][b] = min(dist[a][b], cost);
        else dist[a][b] = cost;
    }

    for (int i = 1; i <= n; i++) {
        floyd(i);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == -1) cout << 0 << " ";
            else cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}