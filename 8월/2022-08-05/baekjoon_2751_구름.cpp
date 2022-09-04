#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    set<int> sInt;
    int n, temp;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        sInt.insert(temp);
    }

    for (const auto& i : sInt)
    {
        cout << i << "\n";
    }

    return 0;
}