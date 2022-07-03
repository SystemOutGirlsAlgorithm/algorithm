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

int v[1005][1005];
int dp[1005][1005];

void solve(int n, int m) {
    memset(dp, 0, sizeof(dp));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &v[i][j);
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (v[i][j] == 0)
                continue;
            dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
            ans = max(dp[i][j], ans);
        }
    }
    
    printf("%d\n", ans);
}

int main() {
    int n, m;
    
    scanf("%d %d", &n, &m);
    while (n != 0 || m != 0) {
        solve(n, m);
        scanf("%d %d", &n, &m);
    }
    
    return 0;
}
