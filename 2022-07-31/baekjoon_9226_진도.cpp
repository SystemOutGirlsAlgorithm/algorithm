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

vector<char> v = {'a', 'e', 'i', 'o', 'u'};

bool isVowel(char c) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == c)
            return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    
    do {
        cin >> s;
        if (s == "#")
            return 0;
        
        int offset = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i]))
                break;
            offset++;
        }
        
        for (int i = 0; i < s.size(); i++) {
            cout << s[(i + offset) % s.size()];
        }
        cout << "ay\n";
        
    } while (true);
    
    return 0;
}
