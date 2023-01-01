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

int dp[105];

int main() {
    int n;
    scanf("%d", &n);
    
    dp[1] = 2;
    dp[2] = 4;
    
    int add = 3;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + add;
        if (i % 3 != 0)
            add++;
    }
    
    printf("%d\n", dp[n]);
    
    return 0;
}
