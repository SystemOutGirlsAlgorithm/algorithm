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
    
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    
    stack<int> st;
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() <= v[i])
            st.pop();
        st.push(v[i]);
        ans += st.size() - 1L;
    }
    
    printf("%lld\n", ans);
    return 0;
}
