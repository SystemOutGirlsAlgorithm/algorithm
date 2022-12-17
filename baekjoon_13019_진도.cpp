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
   string a, b;
    cin >> b;
    cin >> a;
    
    // 알파벳 개수가 같은지 검증
    if (a.size() != b.size()) {
        printf("-1\n");
        return 0;
    }
    
    for (int i = 0; i < a.size(); i++) {
        countAlphabet(a[i], alphabet1);
    }
    
    for (int i = 0; i < b.size(); i++) {
        countAlphabet(b[i], alphabet2);
    }
    
    for (int i = 0; i < 100; i++) {
        if (alphabet1[i] != alphabet2[i]) {
            printf("-1\n");
            return 0;
        }
    }
    
    // 로직 시작
    int ans = 0;
    for (int i = a.size() - 1, j = b.size() - 1; i >= 0 && j >= 0; j--) {
        if (a[i] == b[j]) {
            i--;
            continue;
        }
        ans++;
    }
    
    printf("%d", ans);
    
    return 0;
} 
