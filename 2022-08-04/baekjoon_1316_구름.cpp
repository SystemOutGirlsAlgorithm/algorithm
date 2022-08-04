#include <bits/stdc++.h>
using namespace std;

bool check(string input)
{
    bool ch[26]{false};
    char prev = '0';

    for (const auto& i : input)
    {
        if (prev != i)
        {
            if (ch[i - 'a'] == true)
            {
                return false;
            }
            else
            {
                ch[i - 'a'] = true;
            }
        }

        prev = i;
    }
    
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    int n, res = 0;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> input;
        if (check(input))
        {
            ++res;
        }
    }

    cout << res << '\n';
    
    return 0;
}