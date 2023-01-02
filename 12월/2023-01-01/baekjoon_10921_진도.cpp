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
    int n, k;
    scanf("%d %d", &n, &k);
    
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = i + 1;
    }
    
    vector<int> ans;
    for (int i = n - 1; i > 0; i--) {
        if (k >= i) {
            k -= i;
            ans.push_back(i + 1);
            v[i] = -1;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (v[i] >= 0)
            ans.push_back(v[i]);
        printf("%d ", ans[i]);
    }
    
    
    return 0;
}
