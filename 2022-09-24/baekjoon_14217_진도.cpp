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

bool visited[505];
int height[505];
vector<int> adj[505];
int n, m;

void bfs(int start) {
    memset(visited, false, sizeof(visited));
    memset(height, -1, sizeof(height));
    
    queue<ii> qu;
    qu.emplace(start, 0);
    visited[start] = true;
    
    while(!qu.empty()) {
        ii curr = qu.front();
        qu.pop();
        
        height[curr.xx] = curr.yy;
        
        for (int next: adj[curr.xx]) {
            if (visited[next])
                continue;
            visited[next] = true;
            qu.emplace(next, curr.yy + 1);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        printf("%d ", height[i]);
    }
    printf("\n");
}

void printVector(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        
        if (a == 1) {
            adj[b].push_back(c);
            adj[c].push_back(b);
        } else {
            adj[b].erase(remove(adj[b].begin(), adj[b].end(), c), adj[b].end());
            adj[c].erase(remove(adj[c].begin(), adj[c].end(), b), adj[c].end());
        }
        
        bfs(1);
    }
    
    return 0;
}
