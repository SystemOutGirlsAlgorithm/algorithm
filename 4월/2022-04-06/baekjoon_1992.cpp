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

int arr[100][100];

void solve(int n, int x, int y) {
    if (n == 1) {
        printf("%d", arr[x][y]);
        return;
    }
    
    bool isOne = true, isZero = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i + x][j + y] == 1)
                isZero = false;
            else
                isOne = false;
        }
    }
    
    if (isZero) {
        printf("0");
        return;
    }
    if (isOne) {
        printf("1");
        return;
    }
    
    printf("(");
    solve(n/2, x, y);
    solve(n/2, x, y + n/2);
    solve(n/2, x + n/2, y);
    solve(n/2, x + n/2, y + n/2);
    printf(")");
    
    
}
// ((110(0101))(0010)1(0001))

int main() 
{
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }
    
    solve(n, 0, 0);
    
    return 0;
}