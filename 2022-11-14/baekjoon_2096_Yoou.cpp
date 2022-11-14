// 백준 2096 내려가기
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, idx0, idx1, idx2, temp0, temp1, temp2;

    cin >> n;
    cin >> idx0 >> idx1 >> idx2;
    int ans_max[3] = {idx0, idx1, idx2};
    int ans_min[3] = {idx0, idx1, idx2};
    for(int i = 1; i < n; i++)
    {
        cin >> idx0 >> idx1 >> idx2;
        temp0 = ans_max[0];
        temp1 = ans_max[1];
        temp2 = ans_max[2];

        ans_max[0] = max(temp0 + idx0, temp1 + idx0);
        ans_max[1] = max({temp0 + idx1, temp1 + idx1, temp2 + idx1});
        ans_max[2] = max(temp1 + idx2, temp2 + idx2);

        temp0 = ans_min[0];
        temp1 = ans_min[1];
        temp2 = ans_min[2];

        ans_min[0] = min(temp0 + idx0, temp1 + idx0);
        ans_min[1] = min({temp0 + idx1, temp1 + idx1, temp2 + idx1});
        ans_min[2] = min(temp1 + idx2, temp2 + idx2);
    }
    cout << max({ans_max[0], ans_max[1], ans_max[2]}) << ' ' << min({ans_min[0], ans_min[1], ans_min[2]});
    
    return (0);
}
