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

struct Edge {
    int u, v, d;
};

int par[10005];

int find(int x) {
    if (x == par[x])
        return x;
    return par[x] = find(par[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    par[x] = y;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        par[i] = i;
    
    vector<Edge> edge(m);
    for (int i = 0; i < m; i++)
        scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].d);
    
    sort(all(edge), [](const Edge &l, const Edge &r) {
        return l.d < r.d;
    });
    
    i64 ans = 0;
    for (auto e: edge) {
        if (find(e.u) == find(e.v))
            continue;
        ans += e.d;
        merge(e.u, e.v);
    }
    
    printf("%lld", ans);
    return 0;
}
