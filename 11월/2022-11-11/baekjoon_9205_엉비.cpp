#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int t, n;
pair<int, int> home, festival;
vector<pair<int, int> > shop(100);
int visited[100];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> t; // 테스트 케이스의 개수 t

    while (t--) {
        cin >> n;
        cin >> home.first >> home.second;
        for (int i = 0; i < n; ++i) {
            cin >> shop[i].first >> shop[i].second;
        }
        cin >> festival.first >> festival.second;
        memset(visited, false, sizeof(visited));

        queue<pair<int, int> > que;
        que.push(make_pair(home.first, home.second));

        string result = "sad";
        // 20병 : 20*50 = 1000미터를 갈 수 있다.
        while (!que.empty()) {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            
            if (abs(festival.first - x) + abs(festival.second - y) <= 1000) { // 현재 가지고 있는 맥주로 페스티벌까지 갈 수 있다면
                result = "happy";
                break;
            }
            else { // 현재 가지고 있는 맥주(20)로 페스티벌까지 가지못한다면 -> 편의점 찾기
                for (int i = 0; i < n; ++i) {
                    if (abs(shop[i].first - x) + abs(shop[i].second - y) <= 1000) {
                        if (!visited[i]) {
                            visited[i] = true;
                            que.push(make_pair(shop[i].first, shop[i].second));
                        }
                    }
                }
            }
        }
        cout << result << '\n';
    }

    return 0;
}