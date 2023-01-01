#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <bitset>
#include <stdio.h>
#include <math.h>
#include <sstream>

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using iis = pair<int, string>;
using ii64 = pair<i64, i64>;
using iii = tuple<int, int, int>;

class Mapping
{
  public:
    void init(const vector<i64>& raw, int base = 0)
    {
        start = base;
        arr = raw;
        sort(arr.begin(), arr.end());
        arr.erase(unique(arr.begin(), arr.end()), arr.end());
    }

    int get_idx(int k)
    {
        return start + lower_bound(all(arr), k) - arr.begin();
    }

    int get_value(int idx)
    {
        return arr[idx - start];
    }

    int size()
    {
        return arr.size();
    }

  private:
    int start;
    vector<i64> arr;
};

int main() {
    int n;
    scanf("%d", &n);
    
    vector<i64> v(n);
    for (int i = 0; i < n; i++)
        scanf("%lld", &v[i]);
    
    Mapping m;
    m.init(v);

    for (int i = 0; i < n; i++)
        printf("%d ", m.get_idx(v[i]));

    // 위까지 자표압축 코드
    
    
    
    return 0;
}
