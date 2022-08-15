#include <bits/stdc++.h>
using namespace std;

bool check()
{
    stack<char> st;
    string input;
    cin >> input;

    for (const auto& i : input)
    {
        if (i == '(')
        {
            st.push(i);
        }
        else if (st.empty())
        {
            return false;
        }
        else
        {
            st.pop();
        }
    }

    return st.empty();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        cout << (check() ? "YES" : "NO") << '\n';
    }

    return 0;
}