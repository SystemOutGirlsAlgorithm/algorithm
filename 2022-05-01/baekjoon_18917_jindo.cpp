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
#define MAX 987654321

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

i64 sum;
i64 xorSum;

void solve() {
    i64 a;
    scanf("%lld", &a);
    
    if (a == 1) {
        i64 b;
        scanf(" %lld", &b);
        sum += b;
        xorSum ^=  b;
        return;
    }
    
    if (a == 2) {
        i64 b;
        scanf("%lld", &b);
        sum -= b;
        xorSum ^=  b;
        return;
    }
    
    if (a == 3) {
        printf("%lld\n", sum);
        return;
    }
    
    if (a == 4) {
        printf("%lld\n", xorSum);
        return;
    }
    
    
}

int main() {
    int m;
    scanf("%d", &m);
    
    for (int i = 0; i < m; i++) {
        solve();
    }
    
    return 0;
}