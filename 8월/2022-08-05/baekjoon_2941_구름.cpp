#include <bits/stdc++.h>
using namespace std;

vector<string> vStr{ "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
int res = 0;

int func(const string& str)
{
    for (int i = 0; i < vStr.size(); ++i)
    {
        int index = str.find(vStr[i]);
        if (index == 0) 
        {
            return i;
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str, temp;
    cin >> str;

    int index = 0;

    while(true)
    {
        if (str.length() <= index) break;

        temp = str.substr(index);
        auto te = func(temp);

        if (te == -1)
        {
            ++index;
        }
        else
        {
            index += vStr[te].size();
        }

        ++res;
    }

    cout << res;

    return 0;
}