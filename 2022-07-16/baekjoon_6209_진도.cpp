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
    int d, n, m;
    scanf("%d %d %d", &d, &n, &m);
    
    vector<int> v(n + 2);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i + 1]);
    }
    v[0] = 0;
    v[n + 1] = d;
    sort(all(v));
    
    i64 l = 0, r = d;
    i64 ans;
    
    while (l <= r) {
        i64 mid = (l + r) / 2;
        
        // 삭제해야 할 돌 개수 세기
        int now = 0;
        int removeCnt = 0;
        for (int i = 1; i < v.size(); i++) {
            if (v[i] - v[now] < mid)
                removeCnt++;
            else
                now = i;
        }
        
        // 삭제해야 할 돌 개수가 m보다 작다면
        if (removeCnt <= m)
            ans = mid, l = mid + 1;
        else
            r = mid - 1;
    }
    
    cout << ans;
    
    return 0;
}
