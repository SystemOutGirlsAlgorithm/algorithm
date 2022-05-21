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
    string s;
    cin >> s;
    
    if (s.size() % 2 == 1) {
        printf("Keine Loesung\n");
        return 0;
    }
    
    int cnt = 0;
    queue<string> q;
    for (int i = 0; i < s.size(); i += 2) {
        if (s[i] == '<' && s[i + 1] == '<') {
            cnt++;
            q.push("<<");
        }
        else if (s[i] == '>' && s[i + 1] == '>') {
            cnt++;
            q.push(">>");
        }
        else {
            printf("Keine Loesung\n");
            return 0;
        }
    }
    
    if (cnt % 2 == 1) {
        printf("Keine Loesung\n");
        return 0;
    }
    
    // < 하나만 들어오는 경우 미리 막음
    stack<string> st;
    string ans = "";
    for (; !q.empty(); q.pop()) {
        if (st.empty()) {
            st.push(q.front());
            ans += "[";
            continue;
        }
        
        if (q.front() == st.top()) {
            st.push(q.front());
            ans += "[";
            continue;
        }
        
        st.pop();
        ans += "]";
    }
    
    if (!st.empty()) {
        printf("Keine Loesung\n");
        return 0;
    }
    
    cout << ans << "\n";
    
    return 0;
}
