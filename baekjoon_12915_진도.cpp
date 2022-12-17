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
#include<cassert>

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()
#define MAXV 987654321

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

int alphabet1[100];
int alphabet2[100];

void countAlphabet(char c, int *alphabet) {
    assert(c >= 65);
    assert(c <= 90);
    
    alphabet[c]++;
}

int main() {
    int e, em, m, mh, h;
    scanf("%d %d %d %d %d", &e, &em, &m, &mh, &h);

    int ans = 0;
    for (int x = 0; x <= em; x++) {
        int a = e + x;
        int b = m + (em - x);
        int c = h;
        
        int big = max(b, c);
        int small = min(b, c);
        
        if (mh - (big - small) > 0) {
            b = big + (mh - (big - small)) / 2;
            c = big + (mh - (big - small)) / 2;
        } else {
            b = big;
            c = small + mh;
        }
        
        ans = max(min({a, b, c}), ans);
    }
    
    printf("%d", ans);
    
    return 0;
}
