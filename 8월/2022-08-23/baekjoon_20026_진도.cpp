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
    
    int m = n * (n - 1) / 2;
    vector<int> v(m);
    for (int i = 0; i < v.size(); i++) {
        scanf("%d", &v[i]);
    }
    
    sort(all(v));
    
    // min
    i64 minAns = 0;
    for (int i = 0; i < n - 1; i++) {
        minAns += v[i];
    }
    
    // max
    i64 maxAns = 0;
    int addValue = 1;
    int idx = 0;
    for (int i = 0; i < n - 1; i++, addValue++) {
        maxAns += v[idx];
        idx += addValue;
    }
    
    printf("%lld %lld", minAns, maxAns);
    
    return 0;
}
