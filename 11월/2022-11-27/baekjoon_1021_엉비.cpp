#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

int N, M;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    /* INPUT */
    cin >> N >> M;

    list<int> que;
    for (int i = 1; i <= N; ++i) {
        que.push_back(i);
    }

    /* SOLUTION */
    int temp, ans = 0;
    for (int i = 0; i < M; ++i) {
        cin >> temp;
       
        list<int>::iterator iter = find(que.begin(), que.end(), temp);
        int idx = distance(que.begin(), iter);
        int cnt = 0;
        if (idx == 0) ;
        else if (que.size()/2 < idx) { // 3. 오른쪽으로 이동
            while (que.front() != temp) {
                que.push_front(que.back());
                que.pop_back();
                ++cnt;
            }
        }
        else { // 2. 왼족으로 이동
            while (que.front() != temp) {
                que.push_back(que.front());
                que.pop_front();
                ++cnt;
            }
            
        }

        que.pop_front();
        ans += cnt;
    }

    /* OUTPUT */
    cout << ans;
    return 0;
}