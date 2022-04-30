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

int calc(int x) {
    int cnt = 0;
    while (x > 0) {
        if (x % 2 == 1)
            cnt++;
        x /= 2;
    }
    return cnt;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    if (n <= k) {
        printf("0");
        return 0;
    }
    
    int ans = 0;
    int res;
    while (res = calc(n) > k) {
        ans++;
        n++;
    }
    printf("%d\n", ans);
    
    return 0;
}