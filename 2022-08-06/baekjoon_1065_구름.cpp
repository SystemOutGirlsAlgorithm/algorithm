#include <bits/stdc++.h>
using namespace std;

bool func(int num)
{
    int a = num / 100, b = (num / 10) % 10, c = num % 10;
    return (c - b) == (b - a);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, cnt = 0;
    cin >> n;

    if (n < 100)
    {
        cnt = n;
    }
    else
    {
        // 1 ~ 99까지는 한수
        cnt = 99;

        for (int i = 100; i <= n; ++i)
        {
            if (func(i) == true) ++cnt;
        }
    }

    cout << cnt;

    return 0;
}