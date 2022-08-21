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
int mapv[1005][1005];

struct Edge {
    int u, v, d;
};

void Init(int n) {
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }
}

int Find(int x) {
    if (x == par[x])
        retur x;
    return par[x] = Find(par[x]);
}

void Merge(int x, int y) {
    x = Find(x);
    y = Find(y);
    par[x] = y;
}


int main() {
    int n;
    scanf("%d", &n);
    
   vector<Edge> edge;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mapv[i][j]);
            if (j < i) {
                Edge e;
                e.u = i;
                e.v = j;
                e.d = mapv[i][j];
                edge.push_back(e);
            }
        }
    }
    
    Init(n);
    
    sort(all(edge), [](const Edge &l, const Edge &r) {
       return l.d < r.d; 
    });
    
    i64 ans = 0;
    for (auto e: edge) {
        if (Find(e.u) == Find(e.v))
            continue;
        
        ans += e.d;
        Merge(e.u, e.v);
    }
    
    printf("%lld", ans);
    
    
    return 0;
}n
