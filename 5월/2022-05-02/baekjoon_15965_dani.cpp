#include <iostream>
#include <vector>

using namespace std;

const int n = 7400000;

void eratos(vector<int>&v)
{
    vector <bool> check(n+1, false);
    check[0] = true;
    check[1] = true;
    for (int i=2; i*i<=n; i++) {
        if (check[i] == false) {
            for (int j=i+i; j<=n; j+=i) {
                check[j] = true;
            }
        }
    }
    for (int i=0; i<=n; i++) {
        if (check[i] == false) {
            v.push_back(i);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k;
    vector<int> num;
    cin >> k;
    eratos(num);

    cout << num[k-1] << "\n";
    return 0;
}