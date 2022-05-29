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

    if (n % 2 == 1) {
        printf("1");
        return;
    }

    vector<i64> v(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        v[i] = abs(a - b);
    }

    sort(all(v));

    printf("%d", abs(v[i/2] - v[i/2 - 1]) + 1);
    
    return 0;
}