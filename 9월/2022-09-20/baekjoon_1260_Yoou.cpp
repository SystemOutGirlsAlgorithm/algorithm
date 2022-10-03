#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
queue<int> q;
bool visited[1001];	// 방문 여부 확인
bool adj[1001][1001];	// 인접행렬

void dfs(int pos)
{
	if (visited[pos])
		return;
	visited[pos] = true;
	cout << pos << " ";
	for(int i = 0; i <= N; i++)
	{
		if (adj[pos][i] && !visited[i])
			dfs(i);
	}
}

void bfs(int pos)
{
	int curr;
	q.push(pos);
	visited[pos] = true;
	while (!q.empty())
	{
		curr = q.front();
		q.pop();
		cout << curr << " ";
		for(int i = 0; i <= N; i++)
		{
			if (adj[curr][i] && !visited[i])
			{
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int V, a, b;
	memset(adj, false, sizeof(adj));
	cin >> N >> M >> V;
	for(int i = 0; i < M; i++)
	{
		cin >> a >> b;
		adj[a][b] = true;
		adj[b][a] = true;
	}
	memset(visited, false, sizeof(visited));
	dfs(V);
	cout << "\n";
	memset(visited, false, sizeof(visited));
	bfs(V);
	return (0);
}