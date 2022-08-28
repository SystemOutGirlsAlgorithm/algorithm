#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, tmp;
    cin >> n;
    queue<int> qInt;
    bool flag = false;

    for (int i = 1; i <= n; ++i)
    {
        qInt.push(i);
    }

    while (true)
    {
        if (qInt.size() == 1)
        {
            cout << qInt.front() << '\n';
            qInt.pop();
            break;
        }

        tmp = qInt.front();
        qInt.pop();

        // flag == true라면 맨 뒤로
        if (flag)
        {
            qInt.push(tmp);
        }

        flag = !flag;
    }
    
    return 0;
}