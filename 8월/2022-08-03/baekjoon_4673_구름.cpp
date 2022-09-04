#include <bits/stdc++.h>
using namespace std;

int check(int num)
{
    int sum = num;

    while (num != 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool res[10001]{ false };

    for (int i = 1; i <= 10000; ++i)
    {
        if (int n = check(i); n <= 10000)
        {
            res[n] = true;
        }
    }

    for (int i = 1; i <= 10000; ++i)
    {
        if (res[i] == false)
        {
            cout << i << '\n';
        }
    }
    
    return 0;
}