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
#define MAXV 987654321

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

int v[1000005];

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        v[a]++;
    }
    
    int ans = 0;
   for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        
        if (v[a] == 0)
            ans++;
        else
            v[a]--;
    }
    
    printf("%d\n", ans);
    
    
    return 0;
} 
