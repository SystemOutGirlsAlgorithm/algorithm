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
    i64 a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    
    vector<i64>v(35);
    v[0] = a % c;
    for (int i = 1; i < v.size(); i++)
        v[i] = v[i-1] * v[i-1] % c;
    
    bitset<33> foo(b);
    
    i64 ans = 1;
    for (int i = 0; i < 33; i++) {
        if (foo[i] == 1)
            ans = ans * v[i] % c;
    }

    printf("%lld\n", ans);
    
    return 0;
}