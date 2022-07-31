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

int n, m;
vector<int> adj[100005];
vector<int> rev[100005];
bool dist1[100005], distN[100005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    
    for (int i = 0; i  m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        rev[y].push_back(x);
    }
    
    // dist1
    queue<int> Q;
    Q.push(1);
    dist1[1] = true;
    
    while (!Q.empty())
    {
        int curr = Q.front();
        Q.pop();
        
        for (int next : adj[curr])
        {
            if (dist1[next])
                continue;
            
            dist1[next] = true;
            Q.push(next);
        }
    }
    
    // distN
    Q.push(n);
    distN[n] = true;
    
    while (!Q.empty())
    {
        int curr = Q.front();
        Q.pop();
        
        for (int next : rev[curr])
        {
            if (distN[next])
                continue;
            
            distN[next] = true;
            Q.push(next);
        }
    }
    
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
		int c;
		cin >> c;

		if (dist1[c] && distN[c])
			cout << "Defend the CTP\n";
		else
			cout << "Destroyed the CTP\n";
    }
    
    return 0;
}<
