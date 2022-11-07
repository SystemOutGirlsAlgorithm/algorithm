#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int N, M;
int map[501][501];
bool visited[501][501];
int ans = 0;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x, int cnt, int sum)
{
	if (cnt == 4)
	{
		ans = max(ans, sum);
		return;
	}	
	else if (y < 0 || x < 0 || y >= N || x >= M)
		return;
	else if (visited[y][x])
		return;
	else
	{
		visited[y][x] = true;
		for(int i = 0; i < 4; i++)
			dfs(y + dy[i], x + dx[i], cnt + 1, sum + map[y][x]);
		visited[y][x] = false;
	}
}

int o(int y, int x)
{
	return (map[y][x] + map[y - 1][x] + map[y][x - 1] + map[y][x + 1]);
}

int a(int y, int x)
{
	return (map[y][x] + map[y - 1][x] + map[y + 1][x] + map[y][x + 1]);
}

int u(int y, int x)
{
	return (map[y][x] + map[y][x - 1] + map[y][x + 1] + map[y + 1][x]);
}

int eo(int y, int x)
{
	return (map[y][x] + map[y - 1][x] + map[y + 1][x] + map[y][x - 1]);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	// init info
	cin >> N >> M;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
			cin >> map[i][j];
	}
	memset(visited, false, sizeof(visited));
	// get answer
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			// 1. ㅜ 모양 제외
			dfs(i, j, 0, 0);
			// 2. ㅜ 모양들
			if (i - 1 >= 0 && j - 1 >= 0 && j + 1 < M) 
				ans = max(ans, o(i, j));	//	ㅗ
			if (i - 1 >= 0 && i + 1 < N && j + 1 < M)
				ans = max(ans, a(i, j));	//	ㅏ
			if (i + 1 < N && j - 1 >= 0 && j + 1 < M)
				ans = max(ans, u(i, j));	//	ㅜ
			if (i - 1 >= 0 && i + 1 < N && j - 1 >= 0)
				ans = max(ans, eo(i, j));	//	ㅓ
		}
	}
	cout << ans;
	return (0);
}