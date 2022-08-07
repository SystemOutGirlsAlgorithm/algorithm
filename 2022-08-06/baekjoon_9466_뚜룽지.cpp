#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int T, n;
int connect[100001];
int in_ver[100001];

int main() {
    cin >> T;
    int input;
    while (T--) {
        fill(in_ver, in_ver+100001, 0);
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> input;
            connect[i] = input;
            in_ver[input]++;
        }
        queue<int> que;
        for (int i = 1; i <= n; i++) {
            if (in_ver[i] == 0) {
                que.push(i);
            }
        }
        int out = 0;
        while (!que.empty()) {
            int node = que.front();
            int wish = connect[node];
            que.pop();
            out++;
            if (--in_ver[wish] == 0) que.push(wish);
        }
        cout << out << "\n";
    }
}