#include <iostream>
#include <utility>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;

/* ======= *
 *   BFS
 * ======= */

int visited[101];
bool connected[101][101];
queue<pair<int, int> > q;
int N, M;

void	make_friend(int start)
{
	int curr, cnt;
	visited[start] = 1;
	q.push(make_pair(start, 0));
	while (!q.empty())
	{
		curr = q.front().first;
		cnt = q.front().second;
		q.pop();
		for(int i = 1; i <= N; i++)
		{
			if (connected[curr][i] && visited[i] == 0)
			{
				visited[i] = cnt + 1;
				q.push(make_pair(i, cnt + 1));
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int a, b, temp;
	int cnt = INT_MAX;
	int Bacon = 0;
	memset(connected, false, sizeof(connected));
	cin >> N >> M;
	for(int i = 0; i < M; i++)
	{
		cin >> a >> b;
		connected[a][b] = true;
		connected[b][a] = true;
	}
	for(int i = 1; i <= N; i++)
	{
		temp = 0;
		memset(visited, false, sizeof(visited));
		make_friend(i);
		for(int j = 1; j <= N; j++)
		{
			if (j != i)
				temp += visited[j];
		}
		if (cnt > temp)
		{
			Bacon = i;
			cnt = temp;
		}
	}
	cout << Bacon;
	return(0);
}

/* ================= *
 *  Floyed Warshall
 * ================= */

// #define INF_1389 500000;

// int shortest_dist[101][101];
// bool connected[101][101];
// int N, M;

// void init(void)
// {
// 	int a, b;
// 	memset(connected, false, sizeof(connected));
// 	for(int i = 1; i <= M; i++)
// 	{
// 		cin >> a >> b;
// 		connected[a][b] = true;
// 		connected[b][a] = true;
// 	}
// 	for(int i = 1; i <= N; i++)
// 	{
// 		for (int j = 1; j <= N; j++)
// 		{
// 			if (i == j)
// 				shortest_dist[i][j] = 0;
// 			else if (connected[i][j])
// 				shortest_dist[i][j] = 1;
// 			else
// 				shortest_dist[i][j] = INF_1389;
// 		}
// 	}
// }

// int WFI(void)
// {
// 	int ret, temp;
// 	int sum = INT_MAX;
// 	// a부터 b까지 p를 지나는 경로들
// 	for(int p = 1; p <= N; p++)
// 	{
// 		for(int a = 1; a <= N; a++)
// 		{
// 			for(int b = 1; b <= N; b++)
// 				shortest_dist[a][b] = min(shortest_dist[a][b], shortest_dist[a][p] + shortest_dist[p][b]);
// 		}
// 	}
// 	for(int i = 1; i <= N; i++)
// 	{
// 		temp = 0;
// 		for(int j = 1; j <= N; j++)
// 			temp += shortest_dist[i][j];
// 		if (sum > temp)
// 		{
// 			sum = temp;
// 			ret = i;
// 		}
// 	}
// 	return (ret);
// }

// int main(void)
// {
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	cout.tie(0);

// 	cin >> N >> M;
// 	init();
// 	cout << WFI();
	
// 	return (0);
// }