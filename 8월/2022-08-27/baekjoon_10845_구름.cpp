#include <bits/stdc++.h>
using namespace std;

queue<int> st;

void push() 
{
    int input;
    cin >> input;

    st.push(input);
}

void pop()
{
    if (st.empty())
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << st.front() << '\n';
        st.pop();
    }
}

void size() 
{
    cout << st.size() << '\n';
}

void empty()
{
    cout << st.empty() << '\n';
}

void front()
{
    if (st.empty())
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << st.front() << '\n';
    }
}

void back()
{
    if (st.empty())
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << st.back() << '\n';
    }
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
        else if (tmp.compare("pop") == 0)
            pop();
        else if (tmp.compare("size") == 0)
            size();
        else if (tmp.compare("empty") == 0)
            empty();
        else if (tmp.compare("front") == 0)
            front();
        else if (tmp.compare("back") == 0)
            back();
    }
    
    return 0;
}