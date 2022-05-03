#include <iostream>
#include <vector>

using namespace std;

int gcd(int x, int y)
{
    int temp;
    if (x<y) {
        temp = x;
        x = y;
        y = temp;
    }
    while (y!=0) {
        temp = x;
        x = y;
        y = temp % y;
    }
    return x;
}

void func(vector<pair<int, int>> &num, int n, int &count) 
{
    for (int i=1; i*i<=n; i++) {
        if (i*i == n) {
            num.emplace_back(i, i);
            count++;
        }
        if (n%i == 0) {
            num.emplace_back(i, n/i);
            count++;
        }
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int gcd_n, lcm_n, div, count=0, min = 10e8;
    int temp, ans;
    vector<pair<int, int>> num;
    cin >> gcd_n >> lcm_n;

    if (lcm_n % gcd_n == 0) {
        div = lcm_n / gcd_n;
        func(num, div, count);

        for (int i=0; i<count; i++) {
            if (gcd(num[i].first, num[i].second)==1){
                temp = (num[i].first * gcd_n) + (num[i].second * gcd_n);
                if (min > temp) {
                    min = temp;
                    ans = i;
                }
            }
            
        }
        cout << num[ans].first*gcd_n << ' ' << num[ans].second*gcd_n << "\n";
    }
    return 0;
}