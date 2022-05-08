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
#define MAX 987654321

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

int main() {
    int n, m, k;
    scanf("%d %d", &n, &m);
    
    vector<string> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    scanf("%d", &k);
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        // 행의 불을 켤 수 있는지 검사
        int cntZero = 0;
        for (int j = 0; j < m; j++) {
            if (v[i][j] == '0')
                cntZero++;
        }
        if (cntZero > k || cntZero % 2 != k % 2)
            continue;
        
        // 해당 패턴이 몇 번 나오는지 검사
        int cntPattern = 0;
        for (int j = 0; j < n; j++) {
            if (v[i] == v[j])
                cntPattern++;
        }
        
        ans = max(cntPattern, ans);
    }
    printf("%d\n", ans);
    
    return 0;
}