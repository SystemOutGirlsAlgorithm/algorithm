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
    
    vector<int> crane(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &crane[i]);
    }
    
    int m;
    scanf("%d", &m);
    
    vector<int> box(m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &box[i]);
    }
    
    sort(all(crane), greater<int>());
    sort(all(box), greater<int>());
    
    if (crane[0] < box[0]) {
        printf("-1\n");
        return 0;
    }
    
    int ans = 0;
    while (!box.empty()) {
        ans++;
        for (int i = 0; i < crane.size(); i++) {
            for (int j = 0; j < box.size(); j++) {
                if (crane[i] >= box[j]) {
                    box.erase(box.begin() + j);
                    break;
                }
            }
        }
    }
    printf("%d\n", ans);
    
    return 0;
}
