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
    int n, r, c;
    scanf("%d %d %d", &n, &r, &c);
    
    int ans = 0;
    // printf("ans %d, r %d, c %d\n", ans, r, c);
    do {
        int half = pow(2, n - 1);
        int box = pow(2, 2 * n - 2);
        
        if (r < half && c < half) {       // 구간 1
            ans += 0;
            // printf("1 ");
        }
        else if (r < half && half <= c) { // 구간 2
            ans += box;
            // printf("2 ");
        }
        else if (half <= r && c < half) { // 구간 3
            ans += box * 2;
            // printf("3 ");
        }
        else {                            // 구간 4
            ans += box * 3;
            // printf("4 ");
        }
        
        
        r = r - half >= 0 ? r - half : r;
        c = c - half >= 0 ? c - half : c;
        
        // printf("ans %d, r %d, c %d\n", ans, r, c);
    } while (--n);
    
    printf("%d\n", ans);
    
    return 0;
}