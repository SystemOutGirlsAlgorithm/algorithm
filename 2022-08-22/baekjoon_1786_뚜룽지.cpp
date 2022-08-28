#include <iostream>
#include <string>
#include <vector>
using namespace std;

string T, P;
vector<int> ans;

vector<int> getPi() {
    int m = P.length();
    vector<int> pi(m, 0);

    int j = 0;
    for (int i = 1; i < m; i++) {
        while (j > 0 && P[i] != P[j]) {
            j = pi[j-1];
        }
        if (P[i] == P[j]) {
            pi[i] = ++j;
        }
    }

    return pi;
}

int main() {
    getline(cin, T);
    getline(cin, P);

    vector<int> pi = getPi();

    int j = 0;
    int n = T.length();
    int m = P.length();
    for (int i = 0; i < n; i++) {
        while (j > 0 && T[i] != P[j]) { // 같지 않을 때.
            j = pi[j-1];
        }
        if (T[i] == P[j]) {
            if (j == m-1) { // 똑같다.
                ans.push_back(i-m+1);
                j = pi[j];
            }
            else {
                ++j;
            }
        }
    }
    
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i]+1 << " ";
    }

    return 0;
}