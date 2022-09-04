#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int h, w;
char board[102][102];
int keys[26];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int ans;
int visiting[102][102];

void initial() {
    fill(&visiting[0][0], &visiting[0][0]+10404, 0);
    fill(&board[0][0], &board[0][0]+10404, 0);
    fill(keys, keys+26, 0);
    ans = 0;
}

int inRange(int x, int y) {
    return x >= 0 && x <= h+1 && y >= 0 && y <= w+1;
}

void adven(int x, int y) {
    queue<pair<int, int> > que;
    queue<pair<int, int> > door[26];
    visiting[x][y] = 1;
    que.push(make_pair(x, y));

    while (!que.empty()) {
        int nx = que.front().first;
        int ny = que.front().second;
        que.pop();
        for (int i = 0; i < 4; i++) {
            int nnx = nx+dx[i];
            int nny = ny+dy[i];
            if (inRange(nnx, nny) && !visiting[nnx][nny]) {
                visiting[nnx][nny] = 1;
                if (board[nnx][nny] == '*') continue;
                
                if (board[nnx][nny] >= 'A' && board[nnx][nny] <= 'Z') {
                    if (keys[board[nnx][nny]-'A']) {    // 키가 있다.
                        que.push(make_pair(nnx, nny));
                    }
                    else {
                        door[board[nnx][nny]-'A'].push(make_pair(nnx, nny));
                    }
                }
                else if (board[nnx][nny] >= 'a' && board[nnx][nny] <= 'z') {
                    que.push(make_pair(nnx, nny));
                    if (!keys[board[nnx][nny]-'a']) { // 키가 원래 없었다.
                        keys[board[nnx][nny]-'a'] = 1;
                        
                        while (!door[board[nnx][nny]-'a'].empty()) {
                            que.push(door[board[nnx][nny]-'a'].front());
                            door[board[nnx][nny]-'a'].pop();
                        }
                    }
                }
                else {
                    que.push(make_pair(nnx, nny));
                    if (board[nnx][nny] == '$') ans++;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        initial();

        cin >> h >> w;
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                cin >> board[i][j];
            }
        }

        string s;
        cin >> s;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') break;
            keys[s[i]-'a'] = 1;
        }
        
        adven(0, 0);
        
        cout << ans << endl;
    }
    
}