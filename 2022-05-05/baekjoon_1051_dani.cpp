#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef vector <vector<int>> vvi;

int main() 
{
    int n, m, max, ans = 1;
    vvi table;
    string temp;
    cin >> n >> m;
    table.assign(n, vector<int>(m));
    if (n>m) max = m;
    else max = n;

    for (int i=0; i<n; i++) {
        cin >> temp;
        for (int j=0; j<m; j++) {
            table[i][j] = temp[j] - '0';
        }
    }
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            for (int k=1; k<max+1; k++) {
                if (i+k<n && j+k<m) {
                    if (table[i][j] == table[i+k][j] && table[i][j] == table[i][j+k] && table[i][j] == table[i+k][j+k]) {
                        if (ans < pow(k+1,2)){
                            ans = pow(k+1,2);
                        }
                    }
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}