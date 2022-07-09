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


int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    vector<ii> v(m);
    for (int i = 0; i < v.size(); i++) {
        scanf("%d %d", &v[i].xx, &v[i].yy);
    }
    
    int ans = 0;
    for (int i = 0; i < (1 << m); i++) {
        int dateSum = 0;
        int pageSum = 0;
        for (int j = 0; j < m; j++) {
            if (i & (1 << j)) {
                dateSum += v[j].xx;
                pageSum += v[j].yy;
            }
        }
        if (dateSum <= n)
            ans = max(ans, pageSum);
    }
    
    printf("%d\n", ans);
    
    
    return 0;
}
