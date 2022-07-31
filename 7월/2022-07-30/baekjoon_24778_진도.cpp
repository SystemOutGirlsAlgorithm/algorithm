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

vector<string> flipList = {"111100100", "111010010", "111001001", 
                                        "100111100", "010111010", "001111001", 
                                        "100100111", "01001011", "001001111"};
vector<int> v(9);
int ans = 100;

bool isAllZero() {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] != 0)
            return false;
    }
    return true;
}

void flip(int idx, int filpCount) {
    for (int i = 0; i < flipList[idx].size(); i++) {
        if (flipList[idx][i] == '0')
            continue;
        v[i] = (v[i] + filpCount) % 4;
    }
}

void printVector(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        if (i % 3 == 0)
            printf("\n");
        printf("%d ", v[i]);
    }
    printf("\n");
}

void solve(int idx, int cnt) {
    if (isAllZero()) {
        // printf("all zero: %d\n", cnt);
        ans = min(ans, cnt);
    }
    
    if (idx == 9) {
        return;
    }
    
    // printVector(v);
    
    vector<int> original = v;
    for (int i = 0; i < 4; i++) {
        flip(idx, i);
        solve(idx + 1, cnt + i);
        v = original;
    }
}

int main() {
    for (int i = 0; i < v.size(); i++) {
        scanf("%d", &v[i]);
    }
    
    solve(0, 0);
    
    ans = ans == 100 ? -1 : ans;
    printf("%d", ans);
    
    return 0;
}1
