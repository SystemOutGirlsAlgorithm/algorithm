#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int snakes_and_ladders[101];
bool visited[101];
queue <int> q;

void init_info(void)
{
	int x, y;
	memset(snakes_and_ladders, 0, sizeof(snakes_and_ladders));
	memset(visited, false, sizeof(visited));
	cin >> N >> M;
	for(int i = 0; i < N; i++)
	{
		cin >> x >> y;
		snakes_and_ladders[x] = y;
	}
	for(int i = 0; i < M; i++)
	{
		cin >> x >> y;
		snakes_and_ladders[x] = y;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int ans = 0;
	int curr, size, npos;
	init_info();
	q.push(1);
	visited[1] = true;
	while (!q.empty())
	{
		ans++;
		size = q.size();
		for(int i = 0; i < size; i++)
		{
			curr = q.front();
			q.pop();
			for(int k = 1; k <= 6; k++)
			{
				npos = curr + k;
				if (npos == 100)
				{
					cout << ans;
					exit(0);
				}
				if (npos > 100 || visited[npos])
					continue;
				visited[npos] = true;
				if (snakes_and_ladders[npos] == 0)
					q.push(npos);
				else
					q.push(snakes_and_ladders[npos]);
			}
		}
	}
	return (0);
}