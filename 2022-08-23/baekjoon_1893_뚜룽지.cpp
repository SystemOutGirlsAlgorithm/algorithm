#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> getPi(string s) {
    int s_leng = s.length();
    vector<int> pi(s_leng, 0);
    int j = 0;
    for (int i = 1; i < s_leng; i++) {
        while (j > 0 && s[i] != s[j]) {
            j = pi[j-1];
        }
        if (s[i] == s[j]) {
            pi[i] = ++j;
        }
    }
    return pi;
}

int kmp(string origin, string search) {
    vector<int> ans;
    vector<int> pi = getPi(search);
    int j = 0;
    int o_leng = origin.length();
    int s_leng = search.length();
    for (int i = 0; i < o_leng; i++) {
        while (j > 0 && origin[i] != search[j]) {
            j = pi[j-1];
        }
        if (origin[i] == search[j]) {
            if (j == s_leng-1) {
                ans.push_back(i-s_leng+1);
                j = pi[j];
            }
            else {
                ++j;
            }
        }
    }
    return ans.size();
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        vector<int> ans;
        string A, W, S;
        cin >> A >> W >> S;

        map<char, int> dict;
        for (int i = 0; i < A.length(); i++) {
            dict[A[i]] = i;
        }

        for (int shift = 0; shift < A.length(); shift++) {
            string key = W;

            for (int i = 0; i < W.length(); ++i) {
                key[i] = A[(dict[key[i]] + shift) % A.length()];
            }

            int k = kmp(S, key);
            if (k == 1) {
                ans.push_back(shift);
            }
        }

        if (ans.size() == 0) cout << "no solution" << "\n";
        else if (ans.size() == 1) cout << "unique: " << ans[0] << "\n";
        else {
            cout << "ambiguous: ";
            for (int i = 0; i < ans.size(); ++i) {
                cout << ans[i] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}