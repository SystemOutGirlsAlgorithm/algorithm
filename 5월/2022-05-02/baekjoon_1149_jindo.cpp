#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()
#define MAXN 1e6

using namespace std;
using i64 = long long;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

int main() {
    int n;
    scanf("%d", &n);

    vector<vector<int> > v(n + 5, vector<int>(3, 0));

    for (int i = 1; i <= n; i++)
        scanf("%d %d %d", &v[i][0], &v[i][1], &v[i][2]);

    vector<vector<int> > count(n + 5, vector<int>(3, 0));
    for (int i = 1; i <= n; i++)
    {
        count[i][0] = min(count[i - 1][1], count[i - 1][2]) + v[i][0];
        count[i][1] = min(count[i - 1][0], count[i - 1][2]) + v[i][1];
        count[i][2] = min(count[i - 1][1], count[i - 1][0]) + v[i][2];
    }

    printf("%d\n", min({ count[n][0], count[n][1], count[n][2] }));

    return 0;
}