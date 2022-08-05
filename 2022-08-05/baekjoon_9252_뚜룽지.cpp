#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string S1, S2;
int memo[1001][1001];
vector<char> ans;

int main() {
    cin >> S1;
    cin >> S2;
    for (int i = 1; i <= S1.size(); i++) {
        for (int j = 1; j <= S2.size(); j++) {
            if (S1[i-1] == S2[j-1]) {
                memo[i][j] = memo[i-1][j-1] + 1; 
            }
            else memo[i][j] = max(memo[i][j-1], memo[i-1][j]);
        }
    }

    int x = S1.size(), y = S2.size();
    while (memo[x][y] != 0) {
        if (memo[x][y] == memo[x][y-1]) {
            y--;
        }
        else if (memo[x][y] == memo[x-1][y]) {
            x--;
        }
        else if (memo[x][y] - 1 == memo[x-1][y-1]) {
            ans.push_back(S1[x-1]);
            x--; y--;
        }
    }

    cout << ans.size() << "\n";
    for (int i = ans.size()-1; i > -1; i--) {
        cout << ans[i];
    }

    return 0;
}