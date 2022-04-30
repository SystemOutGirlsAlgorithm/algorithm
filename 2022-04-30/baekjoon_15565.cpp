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

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[i]);
    
    int l = -1, r = -1;
    
    for (int i = 1; i <= n; i++) {
        if (v[i] == 1) {
            l = i, r = i;
            break;
        }
    }
    
    if (l == -1) {
        printf("-1\n");
        return 0;
    }
    
    int cnt = 0;
    int ans = MAX;
    while (r <= n) {
        if (v[r] == 1)
            cnt++;
        if (cnt == k) {
            ans = min(r - l + 1, ans);
            while (l <= r && v[++l] != 1) ;
            cnt--;
        }
        
        r++;
    }
    
    if (ans == MAX) {
        printf("-1\n");
        return 0;
    }

    printf("%d\n", ans);
    
    return 0;
}