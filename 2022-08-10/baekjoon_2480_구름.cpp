#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num[7] = { 0 };
    int tmp, max = INT_MIN;
    for (int i = 0; i < 3; ++i)
    {
        cin >> tmp;
        ++num[tmp];
        if (max <= tmp) max = tmp;
    }

    for (int i = 1; i <= 6; ++i)
    {
        if (num[i] == 3)
        {
            cout << 10000 + i * 1000;
            return 0;
        }
        else if (num[i] == 2)
        {
            cout << 1000 + i * 100;
            return 0;
        }
    }

    cout << max * 100;

    return 0;
}