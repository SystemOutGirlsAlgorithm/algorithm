#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#define xx first
#define yy second

using namespace std;
using i64 = long long;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

bool visited[15];
int arr[15][15];
int ans = 50000000;
int n;

void dfs(int curr, int cnt, int sum)
{
    if (cnt == n && curr == 0) {
        ans = min(ans, sum);
        return;
    }
    
    for (int next = 0; next < n; next++)
    {
        if (visited[next] || arr[curr][next] == 0)
            continue;
        visited[next] = true;
        dfs(next, cnt + 1, arr[curr][next] + sum);
        visited[next] = false;
    }
}

int main() 
{
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    
    dfs(0, 0, 0);

    // ans: 35
    printf("%d\n", ans);
    
    return 0;
}