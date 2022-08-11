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

bool visited[100005];
vector<ii> adj[100005];

struct Edge {
    int u, v, d;
};

int par[100005];

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

void Init(int n) {
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }
}


int main() 
{
    int n, m;
    int start, end;
    scanf("%d %d %d %d", &n, &m, &start, &end);
    Init(n);
    
    vector<Edge> edge(m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].d);
    }
    
    sort(all(edge), [](const Edge &l, const Edge &r) {
        return l.d > r.d;
    });
    
    for (auto e: edge){
        if (Find(e.u) == Find(e.v))
            continue;
        Merge(e.u, e.v);
        adj[e.u].emplace_back(e.v, e.d);
        adj[e.v].emplace_back(e.u, e.d);
    }
    
    memset(visited, false, sizeof(visited));
    
    vector<int> cost(n + 5, 987654321);
    queue<ii> Q;
    Q.push(make_pair(start, 987654321));
    visited[start] = true;
    
    while(!Q.empty()) {
        ii curr = Q.front();
        Q.pop();
        
        // printf("%d %d\n", curr.xx, curr.yy);
        
        for (auto next: adj[curr.xx]) {
            if (visited[next.xx])
                continue;
            visited[next.xx] = true;
            cost[next.xx] = min(cost[curr.xx], next.yy);
            Q.push(next);
        }
    }
    
    if (cost[end] == 987654321)
        printf("0\n");
    else printf("%d\n", cost[end]);
    
    return 0;
}
