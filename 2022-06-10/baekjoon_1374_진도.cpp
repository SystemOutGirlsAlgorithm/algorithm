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
    
    vector<ii> v(n);
    for (int i = 0; i < n; i++) {
        int n;
        scanf("%d %d %d", &n, &v[i].xx, &v[i].yy);
    }
    
    sort(all(v));
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (pq.empty()) {
            pq.push({v[i].yy, v[i].xx});
            count++;
            continue;
        }
        
        auto lec = pq.top();
        if (v[i].xx < lec.xx) { // 강의가 겹치는 경우
            pq.push({v[i].yy, v[i].xx}); // 끝나는 시간 기준으로 넣음
            count++;
            continue;
        }
        
        // 강의가 겹치지 않는 경우
        pq.pop();
        pq.push({v[i].yy, v[i].xx});
    }
    
    printf("%d\n", count);
    
    return 0;
}