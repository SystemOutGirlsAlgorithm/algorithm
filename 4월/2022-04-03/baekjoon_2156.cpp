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
    int n;
    scanf("%d", &n);
    
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    
    vector<int> dp(n);
    dp[0] = v[0];
    dp[1] = v[1] + v[0];
    
    for (int i = 2; i < n; i++) {
        dp[i] = max({dp[i-1], v[i] + dp[i-2], v[i] + v[i-1] + dp[i-3]});
    }
    printf("%d\n", dp[n-1]);
    
    return 0;
}
