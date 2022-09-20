#include <bits/stdc++.h>
using namespace std;

const int max_n = 104;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int arr[max_n][max_n]{0}, visited[max_n][max_n]{0};

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            scanf("%1d", &arr[i][j]);
        }
    }

    queue<pair<int, int>> qInt;
    visited[0][0] = 1;
    qInt.push({0, 0});

    while(!qInt.empty())
    {
        auto [y, x] = qInt.front();
        qInt.pop();

        for (int i = 0; i < 4; ++i)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m || arr[ny][nx] == 0) continue;
            if (visited[ny][nx]) continue;

            visited[ny][nx] = visited[y][x] + 1;
            qInt.push({ny, nx});
        }
    }

    printf("%d", visited[n - 1][m - 1]);

    return 0;
}