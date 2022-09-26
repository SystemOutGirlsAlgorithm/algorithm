#include <bits/stdc++.h>
using namespace std;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int t, n, m, k, x, y, res;

int arr[51][51];
int visited[51][51];

void dfs(int y, int x)
{
    visited[y][x] = 1;

    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

        if (arr[ny][nx] == 1 && !visited[ny][nx])
        {
            dfs(ny, nx);
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;

    while (t--)
    {
        fill(&arr[0][0], &arr[0][0] + 51 * 51, 0);
        fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
        res = 0;

        cin >> m >> n >> k;

        for (int i = 0; i < k; ++i)
        {
            cin >> x >> y;
            arr[y][x] = 1;
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (arr[i][j] == 1 && !visited[i][j]) 
                {
                    dfs(i, j);
                    res++;
                }
            }
        }
        cout << res << '\n';
    }

    return 0;
}