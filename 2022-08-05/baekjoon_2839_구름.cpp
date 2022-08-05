#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, res = -1;
    cin >> n;

    int start = n / 5;
    while (start > 0)
    {
        if ((n - (5 * start)) % 3 == 0) 
        {
            res = start + (n  - (5 * start)) / 3;
            break;
        }

        --start;
    }

    // 3으로만 나눠지는 경우, 예외 처리
    if (res == -1 && n % 3 == 0)
    {
        res = n / 3;
    }

    cout << res;

    return 0;
}