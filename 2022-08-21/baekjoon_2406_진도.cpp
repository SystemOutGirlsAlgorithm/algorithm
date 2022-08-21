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

int par[1005];
int n, m;

struct Edge {
    int u, v, d;
};

void Init() {
    for (int i = 1; i <= n; i++)
        par[i] = i;
}

int Find(int x) {
    if (x == par[x])
        return x;
    return par[x] = Find(par[x]);
}

void Merge(int x, int y) {
    x = Find(x);
    y = Find(y);
    par[x] = y;
}

int main() {
    scanf("%d %d", &n, &m);
    
    Init();
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        Merge(x, y);
    }
    
    vector<Edge> edge;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            scanf("%d", &x);
            
            if (i == 1 || j == 1 || i <= j)
                continue;
            
            Edge e;
            e.u = i;
            e.v = j;
            e.d = x;
            
            if (Find(e.u) == Find(e.v))
                continue;
            
            edge.push_back(e);
        }
    }
    
    sort(all(edge), [](const Edge &l, const Edge &r) {
        return l.d < r.d;
    });
    
    i64 price = 0;
    vector<ii> ans;
    for (auto e: edge) {
        if (Find(e.u) == Find(e.v))
            continue;
        
        price += e.d;
        ans.emplace_back(e.u, e.v);
        
        Merge(e.u, e.v);
    }
    
    printf("%lld %d\n", price, ans.size());
    for (int i = 0; i < ans.size(); i++) {
        printf("%d %d\n", ans[i].xx, ans[i].yy);
    }
    
    
    return 0;
}
