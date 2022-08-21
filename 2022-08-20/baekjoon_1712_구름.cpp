#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c, res = 1;
    cin >> a >> b >> c;

    if (b >= c)
    {
        cout << -1;
        return 0;
    }

    cout << a / (c - b) + 1;

    return 0;
}