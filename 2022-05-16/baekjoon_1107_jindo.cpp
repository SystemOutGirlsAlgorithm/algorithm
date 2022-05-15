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
    
    int m;
    scanf("%d", &m);
    
    vector<int> v(m);
    for (int i = 0; i < m; i++)
        scanf("%d", &v[i]);
    
    int ans = abs(100 - n);
    for (int i = 0; i < 1000001; i++) {
        string s = to_string(i);

        bool isOk = true;
        for (int j = 0; j < s.size(); j++) {
            if (find(all(v), s[j] - '0') != v.end()) {
                isOk = false;
                break;
            }
        }
        if (isOk)
            ans = min(ans, int(s.size() + abs(i - n)));
    }
    printf("%d\n", ans);
    
    return 0;
}
