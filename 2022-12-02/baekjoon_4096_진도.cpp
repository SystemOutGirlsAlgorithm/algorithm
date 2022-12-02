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

bool isPalindrome(string s) {
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - (i + 1)])
            return false;
    }
    return true;
}

string fillZerostring s, int size) {
    return string(size - min(size, (int)s.size()), '0') + s;
}

string addString(string s, int num) {
    int size = s.size();
    return fillZero(to_string(stoi(s) + num), size);
}

int main() {
    string origin;
    while (cin >> origin) {
        if (origin == "0")
            break;
        for (int i = 0; ; i++) {
            if (isPalindrome(addString(origin, i))) {
                cout << i << endl;
                break;
            }
        }
    }
    
    return 0;
}(
