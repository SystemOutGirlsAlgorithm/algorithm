#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, min = 10e8, count=0, same=0;
    cin >> t;

    while(t--) {
        cin >> n;
        count = 0; min = 10e8;
        vector<int> candy(n,0);

        for (int i=0; i<n; i++) {
            cin >> candy[i];
            if (min>candy[i]) min = candy[i];
        }

        for (int i=0; i<n; i++) {
            if (min != candy[i]) {
                count += (candy[i]-min);
            }
            if (min == candy[i]) same++;
        }
        if (same==n) {
            cout << "0" << "\n";
        }
        else if (n == 1) {
            cout << "0" << "\n";
        }
        else {
            cout << count << "\n";
        }
        candy.clear();
    }

    return 0;
}