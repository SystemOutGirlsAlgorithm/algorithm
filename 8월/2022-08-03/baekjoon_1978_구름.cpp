#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, max = INT_MIN, res = 0;
    vector<int> vInput;
    vector<bool> vRes;

    cin >> n;
    vInput.resize(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> vInput[i];
        if (vInput[i] > max) max = vInput[i];
    }

    vRes.resize(max);

    for (int i = 2; i <= max; ++i)
    {
        if (vRes[i] == true) continue;
        for (int j = i * 2; j <= max; j += i)
        {
            vRes[j] = true;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (vInput[i] != 1 && vRes[vInput[i]] == false)
        {
            ++res;
        }
    }

    cout << res;
    
    return 0;
}