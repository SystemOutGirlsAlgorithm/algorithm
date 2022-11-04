// 백준 1167 트리의 지름
#include <iostream>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;

int v;
vector<pair<int, int> > adj_list[100001];
bool visited[100001];
int node;
int len = 0;

/*
 * 임의의 정점에서 dfs로 가장 멀리 떨어져 있는 정점을 찾는다.
 * 그 정점을 시작점으로 해서 dfs로 가장 멀리 떨어져 있는 정점을 찾으면
 * 그 두 점 사이의 거리 (즉 마지막 dfs의 결과물) 가 바로 트리의 지름이 된다.
*/

void dfs(int start, int curr, int total_len)
{
    int n, n_len;
    visited[curr] = true;
    if (len < total_len)
    {
        len = total_len;
        node = curr;
    }
    for(int i = 0; i < adj_list[curr].size(); i++)
    {
        n = adj_list[curr][i].first;
        n_len = adj_list[curr][i].second;
        if (!visited[n])
            dfs(start, n, total_len + n_len);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b, w;
    cin >> v;
    for(int i = 0; i < v; i++)
    {
        cin >> a;
        cin >> b;
        while (b != -1)
        {
            cin >> w;
            adj_list[a].push_back(make_pair(b, w));
            adj_list[b].push_back(make_pair(a, w));
            cin >> b;
        }
    }

    memset(visited, false, sizeof(visited));
    dfs(1, 1, 0);
    memset(visited, false, sizeof(visited));
    dfs(node, node, 0);

    cout << len;

    return (0);
}