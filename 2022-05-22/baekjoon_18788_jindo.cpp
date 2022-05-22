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

int nextPosition(int idx, int s, int e) {
    if (s <= idx && idx <= e)
        return idx + (e - s) - 2 * (idx - s);
    return idx;
}

void printVector(vector<int> &v) {
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << "\n";
}

int main() {
    int n, k, a1, a2, b1, b2;
    scanf("%d %d %d %d %d %d", &n, &k, &a1, &a2, &b1, &b2);
    
    int v[105];
    for (int i = 1; i <= n; i++)
        v[i] = i;
    
    int cnt = 1;
    while (true) {
        reverse(v + a1, v + a2 + 1);
        reverse(v + b1, v + b2 + 1);
        
        bool isOk = true;
        for (int i = 1; i <= n; i++) {
            if (i != v[i])
                isOk = false;
        }
        if (isOk) break;
        cnt++;
    }
    
    k %= cnt;
    while(k--) {
        reverse(v + a1, v + a2 + 1);
        reverse(v + b1, v + b2 + 1);
    }
    
    for (int i = 1; i <= n; i++) {
        printf("%d\n", v[i]);
    }
    
    return 0;
}
