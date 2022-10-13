/**********************************
 * 2022 10 13
 * baekjoon 11725 트리의 부모 찾기
 **********************************/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N;
vector<int> connected[100001];
queue <int> q;
int parent[100001];

void bfs(void)
{
    int prev, curr;
    q.push(1);
    parent[1] = 1;
    while (!q.empty())
    {
        prev = q.front();
        q.pop();
        for(int i = 0; i < connected[prev].size(); i++)
        {
            curr = connected[prev][i];
            if (parent[curr] != 0)
                continue;
            parent[curr] = prev;
            q.push(curr);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int input1, input2;
    memset(parent, 0, sizeof(parent));
    cin >> N;
    for(int i = 0; i < N - 1; i++)
    {
        cin >> input1 >> input2;
        connected[input1].push_back(input2);
        connected[input2].push_back(input1);
    }

    bfs();
    
    for(int i = 2; i <= N; i++)
        cout << parent[i] << '\n';

    return (0);
}