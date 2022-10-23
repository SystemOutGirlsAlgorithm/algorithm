// 백준 13549 숨바꼭질 3
#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

int n, k;
queue <pair<int, int> > subin_pos_q; // pos, second
bool visited[100001];
int answer = INT_MAX;

void strange_bfs(void)
{
    int q_size, subin_pos, second, temp;
    while (!subin_pos_q.empty())
    {
        subin_pos = subin_pos_q.front().first;
        second = subin_pos_q.front().second;
        subin_pos_q.pop();
        if (subin_pos == k)
        {
            answer = min(answer, second);
            return;
        }
        temp = subin_pos * 2;
        while (temp != 0 && temp <= 100000)
        {
            if (temp == k)
            {
                answer = min(answer, second);
                return;
            }
            if (!visited[temp])
            {
                subin_pos_q.push(make_pair(temp, second));
                visited[temp] = true;
            }
            temp *= 2;
        }
        if (subin_pos - 1 >= 0 && !visited[subin_pos - 1])
        {
            visited[subin_pos - 1] = true;
            subin_pos_q.push(make_pair(subin_pos - 1, second + 1));
        }
        if (subin_pos + 1 <= 100000 && !visited[subin_pos + 1])
        {
            visited[subin_pos + 1] = true;
            subin_pos_q.push(make_pair(subin_pos + 1, second + 1));
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(visited, false, sizeof(visited));
    cin >> n >> k;
    subin_pos_q.push(make_pair(n, 0));
    visited[n] = true;
    n *= 2;
    while (n != 0 && n <= 100000)
    {
        subin_pos_q.push(make_pair(n, 0));
        visited[n] = true;
        n *= 2;
    }
    strange_bfs();
    cout << answer;
    return (0);
}