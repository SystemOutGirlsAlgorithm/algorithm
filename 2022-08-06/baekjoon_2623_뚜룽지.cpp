#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<int> priority[1001];
int in_ver[1001];

int main() {
    cin >> N >> M;
    int n;
    for (int i = 0; i < M; i++) {
        cin >> n;
        int a, b;
        cin >> a;
        for (int j = 1; j < n; j++) {
            if (j%2==0) {
                cin >> a;
                priority[b].push_back(a);
                in_ver[a]++;
            }
            else {
                cin >> b;
                priority[a].push_back(b);
                in_ver[b]++;
            }
        }
    }

    queue<int> que;
    vector<int> ans;
    for (int i = 1; i <= N; i++) {
        if (in_ver[i] == 0) que.push(i);
    }
    
    for (int j = 0; j < N; j++) {
        if (que.empty()) { // cycle 존재한다는것.
            break;
        }
        int node = que.front();

        ans.push_back(node);
        que.pop();
        for (int i = 0; i < priority[node].size(); i++) {
            if (--in_ver[priority[node][i]] == 0) {
                que.push(priority[node][i]);
            }
        }
    }

    if (ans.size() != N) cout << 0;
    else {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << "\n";
        }
    }

    return 0;
}