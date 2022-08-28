#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x, y;
    cin >> n;

    vector<pair<int, int>> vRes;

    for (int i = 0; i < n; ++i)
    {
        cin >> x >> y;
        vRes.push_back(make_pair(x, y));
    }

    sort(vRes.begin(), vRes.end());

    for (int i = 0; i < n; ++i)
    {
        cout << vRes[i].first << ' ' << vRes[i].second << '\n';
    }
    
    return 0;
}