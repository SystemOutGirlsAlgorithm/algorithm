#include <bits/stdc++.h>
using namespace std;

stack<int> st;

void push() 
{
    int input;
    cin >> input;

    st.push(input);
}

void top() 
{
    if (st.empty())
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << st.top() << '\n';
    }
}

void size() 
{
    cout << st.size() << '\n';
}

void pop()
{
    if (st.empty())
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << st.top() << '\n';
        st.pop();
    }
}

void empty()
{
    cout << st.empty() << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    string tmp;

    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;

        if (tmp.compare("push") == 0)
            push();
        else if (tmp.compare("top") == 0)
            top();
        else if (tmp.compare("size") == 0)
            size();
        else if (tmp.compare("pop") == 0)
            pop();
        else if (tmp.compare("empty") == 0)
            empty();
    }
    
    return 0;
}