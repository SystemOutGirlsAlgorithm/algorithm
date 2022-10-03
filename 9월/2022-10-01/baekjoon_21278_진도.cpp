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

vector<int> adj[105];
bool visited[105];
vector<int> height(105, MAXV);
ii ans;
int ansv = MAXV;

void bfs(int start) {
    queue<ii> q;
    q.emplace(start, 0);
    visited[start] = tre;
    
    while(!q.empty()) {
        ii curr = q.front();
        q.pop();
        
        height[curr.xx] = min(curr.yy, height[curr.xx]);
        for (auto next: adj[curr.xx]) {
            if (visited[next])
                continue;
            visited[next] = true;
            q.emplace(next, curr.yy + 1);
        }
    }
}

void combination(vector<int> &v, int n, int r) {
    vector<bool> check(n - r, false);
	check.insert(check.end(), r, true);

	do {
	    vector<int> x;
		for (int i = 0; i < n; i++) {
			if (!check[i])
			    continue;
			// do something
// 			cout << v[i];
			x.push_back(v[i]);
		}
// 		cout << "\n";
		
		memset(visited, false, sizeof(visited));
		fill(height.begin(), height.end(), MAXV);
		bfs(x[0]);
		
		memset(visited, false, sizeof(visited));
		bfs(x[1]);
		
		// 거리의 합
		int sum = 0;
		for (int i = 1; i <= n; i++) {
		    sum += height[i];
		}
// 		cout << "sum: " << sum << endl;
		
		if (sum <= ansv) {
		    ansv = sum;
		    ans.xx = x[0];
		    ans.yy = x[1];
		}
		
	} while (next_permutation(check.begin(), check.end()));
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> v(n);
    for (int i = 1; i <= n; i++) {
        v[i-1] = i;
    }
    
    combination(v, n, 2);
    printf("%d %d %d\n", ans.xx, ans.yy, ansv * 2);
    
    return 0;
}u
