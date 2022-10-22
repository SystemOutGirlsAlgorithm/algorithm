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


int main() {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    
    vector<int> va(a);
    for (int i = 0; i < a; i++)
        scanf("%d", &va[i]);
    vector<int> vb(b);
    for(int i = 0; i < b; i++)
        scanf("%d", &vb[i]);
    
    sort(all(va), greater<int>());
    
    i64 ans = n % 2 == 0 ? 0 : va[0];
    for (int i = n % 2; i + 1 < a; i += 2) {
        vb.push_back(va[i] + va[i + 1]);
    }
    
    sort(all(vb), greater<int>());
    
    for (int i = 0; i < n/2; i++) {
        ans += vb[i];
    }
    
    printf("%lld", ans);
    
    
    return 0;
} 
