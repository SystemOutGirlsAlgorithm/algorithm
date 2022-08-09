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

int par[100005];

int find(int x) {
    if (x == par[x])
        return x;
    return par[x] = find(par[x]);
}

void init(int n) {
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    par[x] = y;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    init(n);
    
    vector<Edge> edge(m);
    for (int i = 0; i < m; i++) 
        scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].d);
    
    sort(all(edge), [](const Edge &l, const Edge &r){
        return l.d < r.d;
    });
    
    int ans = 0;
    int maxRoad = 0;
    for (int i = 0; i < edge.size(); i++) {
        if (find(edge[i].u) == find(edge[i].v))
            continue;
        
        ans += edge[i].d;
        maxRoad = max(maxRoad, edge[i].d);
        merge(edge[i].u, edge[i].v);
    }
    
    printf("%d\n", ans - maxRoad);
    
    return 0;
}
