#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, H, ans = 4;
vector<pair<int, int> > isAble;
bool ladder[31][11];

bool isI() {
    for (int i = 0; i < N; ++i) {
        int y = i;
        
        for (int x = 0; x < H; ++x) {
            if (y-1 >= 0 && ladder[x][y-1]) {
                y = y-1;
            }
            else if (y+1 < N && ladder[x][y]) {
                y = y+1;
            }
        }

        if (i != y) return false;
    }
    return true;
}


void bactr(int cnt, int idx) {
    if (cnt > 3) return ;

    if (idx >= isAble.size()) {
        if (isI()) {
            if (cnt <= ans) ans = cnt;
        }
        return ;
    }

    // 해당 Idx 에 사다리를 놓지 않음.
    bactr(cnt, idx+1);

    // 해당 idx 에 사다리 놓기
    int a = isAble[idx].first, b = isAble[idx].second;
    if (b-1 < 0 || !ladder[a][b-1]) { // !(b-1 >= 0 && ladder[a][b-1])
        ladder[a][b] = true;
        bactr(cnt+1, idx+1);
        ladder[a][b] = false;
    }

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    /* INPUT */
    cin >> N >> M >> H;

    int a, b;
    for (int i = 0; i < M; ++i) {
        cin >> a >> b;
        ladder[a-1][b-1] = true;
    }

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < N-1; ++j) {
            if (!ladder[i][j]) isAble.push_back(make_pair(i, j));
        }
    }

    /* SOLUTION */
    bactr(0, 0);

    if (ans > 3) cout << -1;
    else cout << ans;

    return 0;
}