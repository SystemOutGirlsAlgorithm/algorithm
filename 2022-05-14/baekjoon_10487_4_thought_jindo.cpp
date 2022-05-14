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

#define SUM 1000000

string ans[3000000];

void solve(vector<char> perm) {
    
    
    string s = "";
    for(int i = 0; i < perm.size(); i++)
    {
        s += "4 ";
        s += perm[i];
        s += " ";
    }
    s += "4 = ";
    
    // 곱셈 계산용
    stack<string> st;
    st.push("4");
    for(int i = 0; i < perm.size(); i++)
    {
        if (perm[i] == '*') {
            string tmp = st.top();
            st.pop();
            st.push(to_string(stoi(tmp) * 4));
            continue;
        }
        else if (perm[i] == '+')
            st.push("+");
        else if (perm[i] == '-')
            st.push("-");
        else if (perm[i] == '/') {
            string tmp = st.top();
            st.pop();
            st.push(to_string(stoi(tmp) / 4));
            continue;
        }
        st.push("4");
    }
    
    // while(!st.empty()) {
    //     cout << st.top();
    //     st.pop();
    //     cout << endl;
    // }
    
    // 스택 뒤집음....
    stack<string> st2;
    while(!st.empty()) {
        st2.push(st.top());
        st.pop();
    }
    
    
    // 덧셈 계산용
    int res = stoi(st2.top());
    st2.pop();
    while(!st2.empty()) {
        if (st2.top() == "+") {
            st2.pop();
            res += stoi(st2.top());
            st2.pop();
        }
        else if (st2.top() == "-") {
            st2.pop();
            res -= stoi(st2.top());
            st2.pop();
        }
    }
    
    s += to_string(res);
    
    // cout << s << endl;
    
    ans[res + SUM] = s;
}

void repeatPermutation(vector<char> vec, vector<char> perm, int depth)
{
    if (depth == perm.size())
    {
        solve(perm);
        
        return;
    }
    
    for(int i = 0; i < vec.size(); i++)
    {
        perm[depth] = vec[i];
        repeatPermutation(vec, perm, depth + 1);
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    const int r = 3;
    
    vector<char> v = {'*', '+', '-', '/'};
    vector<char> perm(r);
    
    repeatPermutation(v, perm, 0);
    
    
    int m;
    cin >> m;
    
    for (int i = 0; i < m; i++) {
        int n;
        cin >> n;
        
        if (ans[n + SUM] == "") {
            cout << "no solution\n";
            continue;
        }
        
        cout << ans[n + SUM] << "\n";
    }
    
    
    
    return 0;
}