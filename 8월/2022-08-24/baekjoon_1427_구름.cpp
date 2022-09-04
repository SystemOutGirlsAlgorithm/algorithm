#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    multimap<char, int, greater<char>> mmRes;
    string input;
    cin >> input;

    for (const auto& i : input)
    {
        auto tmp = mmRes.find(i); 
        if (tmp != mmRes.end())
        {
            ++tmp->second;
        }
        else
        {
            mmRes.insert(make_pair(i, 1));
        }
    }

    for (const auto& it : mmRes)
    {
        for (int i = 0; i < it.second; ++i)
        {
            cout << it.first;
        }
    }
    
    return 0;
}