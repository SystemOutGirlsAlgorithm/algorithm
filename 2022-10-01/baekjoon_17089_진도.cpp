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
#define MAXV 987654321

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

vector<int> adj[4005];
map<ii, bool> friendm;
int ans = MAXV;
int numberOfFriend[4005];
bool visited[4005];

void dfs(int x, int start, int cnt, int num){
    if(cnt == 3){
        if(!riendm[make_pair(start, x)]) 
            return;
        ans = min(num-6, ans);
        return ;
    }


    for(int i = 0; i < numberOfFriend[x]; i++){
        int nxt = adj[x][i];

        if(visited[nxt]) continue;
        visited[nxt]=true;
        dfs(nxt, start, cnt+1, num + numberOfFriend[nxt]);
        visited[nxt]=false;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        
        adj[u].push_back(v);
        adj[v].push_back(u);
        
        friendm[make_pair(u, v)] = true;
        friendm[make_pair(v, u)] = true;
        
        numberOfFriend[u]++;
        numberOfFriend[v]++;
    }
    
    for (int i = 1; i <= n; i++) {
        if (visited[i])
            continue;
        visited[i] = true;
        dfs(i, i, 1, numberOfFriend[i]);
    }
    
    printf("%d", ans == MAXV ? -1 : ans);
    
    return 0;
}f
