/*
 * state machine
 */

#include <iostream>
#include <string>
using namespace std;

int T;
string s;
int state[9][2] = { {7, 1},
                    {2, -1},
                    {3, -1},
                    {3, 4},
                    {7, 5},
                    {6, 5},
                    {3, 0},
                    {-1, 8},
                    {7, 1} };

int main() {
    cin >> T;

    while (T--) {
        cin >> s;
        int states = 0;
        int isPattern = 1;
        for (int i = 0; i < s.length(); i++) {
            if ((states = state[states][s[i]-'0']) == -1) {
                isPattern = 0;
                break;
            } 
        }
        if (isPattern && (states == 0 || states == 4 || states == 5 || states == 8)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}