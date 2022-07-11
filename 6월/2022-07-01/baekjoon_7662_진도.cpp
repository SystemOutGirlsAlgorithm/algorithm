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

void solve() {
    int k;
    cin >> k;
    
    priority_queue<int, vector<int>, less<int>> pqMax;
    priority_queue<int, vector<int>, greater<int>> pqMin;
    map<int, int> mp;
    
    for (int i = 0; i <k; i++) {
        string s; int n;
        cin >> s >> n;
        if (s == "I") {
            pqMax.push(n);
            pqMin.push(n);
            // cout << pqMax.top() << " " << pqMin.top() << "\n";
            mp[n]++;
            continue;
        }
        
        if (n == 1) {
            while (!pqMax.empty() && mp[pqMax.top()] == 0)
                pqMax.pop();
            if (!pqMax.empty()) {
                mp[pqMax.top()]--;
                pqMax.pop();
            }
        } else {
            while (!pqMin.empty() && mp[pqMin.top()] == 0)
                pqMin.pop();
            if (!pqMin.empty()) {
                mp[pqMin.top()]--;
                pqMin.pop();
            }
        }
    }
    
    while (!pqMax.empty() && mp[pqMax.top()] == 0)
        pqMax.pop();
    while (!pqMin.empty() && mp[pqMin.top()] == 0)
        pqMin.pop();
    
    if (pqMax.empty() && pqMin.empty())
        cout << "EMPTY\n";
    else
        cout << pqMax.top() << " " << pqMin.top() << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        solve();
    }
    
    return 0;
} 
