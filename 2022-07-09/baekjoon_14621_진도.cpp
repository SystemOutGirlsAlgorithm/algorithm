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
#include <stdlib.h>
#include <string.h>

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

i64 p[1010];

int Find(int a) {
    if(p[a] == a)
        return a;
    return p[a] = Find(p[a]);
}

int Union(int x, int y) {
    int px = Find(x);
    int py = Find(y);
    
    if (px == py)
        return 0;
    p[px] = py;
    return 1;
}

bool cmp(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2)
{
    return p1.second < p2.second;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vector<string> school(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> school[i];
        p[i] = i; // UnionFind 초기화
    }
    
    vector<pair<ii, int>> v;
    for (int i = 0; i < m; i++) {
		int from, to, d;
		cin >> from >> to >> d;
		if (school[from] != school[to]) // 조건에 일치하는 경우에 간선 추가ㅁ
		    v.push_back({{from, to}, d});
	}
	
    int schoolCnt = 0;
    int ans = 0;
    
    sort(all(v), cmp);
    
    for (auto edge: v) {
        if (Union(edge.xx.xx, edge.xx.yy) == 0)
            continue;
        
        ans += edge.yy;
        schoolCnt++;
    }
    
    if (schoolCnt == n - 1)
        cout << ans << "\n";
    else
        cout << "-1\n";
    
    return 0;
}
