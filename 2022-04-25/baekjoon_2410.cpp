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
#include <cstring>
#define xx first
#define yy second

using namespace std;
using i64 = long long;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

#define MOD 1000000000
int ans;
int dp[1000005];

int main() 
{
    int n;
    scanf("%d", &n);
    
    dp[0] = 1;
    
    for (int two = 1; two <= n; two *= 2) {
        for (int i = 0; i <= n; i++) {
            if (i - two >= 0)
                dp[i] = (dp[i] + dp[i - two]) % MOD;
        }
    }
    
    printf("%d", dp[n]);
    
    return 0;
}