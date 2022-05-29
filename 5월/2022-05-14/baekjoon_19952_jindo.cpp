#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <bitset>
#include <stdio.h>
#include <math.h>
#include <sstream>

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

int wall[105][105];
bool visited[105][105];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

int solve() {
    int h, w, o, f, startX, startY, endX, endY;
    scanf("%d %d %d %d %d %d %d %d", &h, &w, &o, &f, &startX, &startY, &endX, &endY);
    
    memset(wall, 0, sizeof(wall));
    memset(visited, false, sizeof(visited));

    
    for (int i = 0; i < o; i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        
        wall[x][y] = z;
    }
    
    queue<iii> q;
    q.emplace(startX, startY, f);
    visited[startX][startY] = true;
    
    while (!q.empty())
    {
        auto [x, y, z] = q.front();
        q.pop();

        if (x == endX && y == endY)
        {
            printf("잘했어!!\n");
            return 0;
        }
        
        if (z <= 0) continue;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 1 || nx > h || ny < 1 || ny > w || visited[nx][ny]) continue;
            if (wall[nx][ny]-wall[x][y] > z) continue;

            q.emplace(nx, ny, z - 1);
            visited[nx][ny] = true;
        }
    }

    printf("인성 문제있어??\n");
    return 0;
}

int main() {
    int t;
    scanf("%d", &t);
    
    for(int i = 0; i < t; i++) {
        solve();
    }
    
    return 0;
}