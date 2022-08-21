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

int n;
int par[1000005];
int mapv[1005][1005];

void Init() {
    for (int i = 0; i <= n * n; i++) {
        par[i] = i;
    }
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

int convertIndex(int x, int y) {
    return n * x + y;
}

ii convertValue(int idx) {
    ii res;
    res.xx = idx / n;
    res.yy = idx % n;
    return res;
}

int main() 
{
    scanf("%d", &n);
    if (n == 1) {
        printf("0\n");
        return 0;
    }
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &mapv[i][j]);
    
    Init();
    vector<Edge> edge;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            Edge e;
            e.u = convertIndex(i, j - 1);
            e.v = convertIndex(i, j);
            e.d = abs(mapv[i][j] - mapv[i][j - 1]);
            edge.push_back(e);
            
            e.u = convertIndex(j - 1, i);
            e.v = convertIndex(j, i);
            e.d = abs(mapv[j][i] - mapv[j - 1][i]);
            edge.push_back(e);
        }
    }
    
    sort(all(edge), [](const Edge &l, const Edge &r) {
        return l.d < r.d;
    });
    

    for (auto e: edge) {
        if (Find(e.u) == Find(e.v))
            continue;
        Merge(e.u, e.v);
        if (Find(convertIndex(0, 0)) == Find(convertIndex(n-1, n-1))) {
            printf("%d\n", e.d);
            return 0;
        }
    }
    
    return 0;
} 
