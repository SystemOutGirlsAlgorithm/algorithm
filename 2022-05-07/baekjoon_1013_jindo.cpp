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

bool solve(string s) {
    int state = 0;
    
    for (int i = 0; i < s.size(); i++) {
        if (state == 0) {
            if (s[i] == '0') {
                state = 1;
            }
            else {
                state = 2;
            }
        }
        
        else if (state == 1) {
            if (s[i] == '0') {
                return false;
            }
            else {
                state = 0;
            }
        }
        
        else if (state == 2) {
            if (s[i] == '0') {
                state = 3;
            }
            else {
                return false;
            }
        }
        
        else if (state == 3) {
            if (s[i] == '0') {
                state = 4;
            }
            else {
                return false;
            }
        }
        
        else if (state == 4) {
            if (s[i] == '0') {
                state = 4;
            }
            else {
                state = 5;
            }
        }
        
        else if (state == 5) {
            if (s[i] == '0') {
                state = 1;
            }
            else {
                state = 6;
            }
        }
        
        else if (state == 6) {
            if (s[i] == '0') {
                state = 7;
            }
            else {
                state = 6;
            }
        }
        
        else if (state == 7) {
            if (s[i] == '0') {
                state = 4;
            }
            else {
                state = 0;
            }
        }
    }
    
    if (state == 0 || state == 5 || state == 6)
        return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<string> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int i = 0; i < n; i++) {
        string res = solve(v[i]) ? "YES" : "NO";
        cout << res << "\n";
    }
    
    return 0;
}