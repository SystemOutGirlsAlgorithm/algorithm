#include <iostream>
#include <tuple>
#include <queue>
#include <string>
#include <cstring>
#include <climits>
using namespace std;

int N, M;
int ans;
string map[100];
bool visited[100][100];
queue<tuple<int, int, int> > q;
int dir_y[4] = {-1, 0, 1, 0};
int dir_x[4] = {0, 1, 0, -1};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	memset(visited, false, sizeof(visited));
	for(int i = 0; i < N; i++)
		cin >> map[i];
	q.push(make_tuple(0, 0, 1));
	int pos_y, pos_x, cnt;
	while (!q.empty())
	{
		pos_y = get<0>(q.front());
		pos_x = get<1>(q.front());
		cnt = get<2>(q.front());
		q.pop();
		if (pos_y == N - 1 && pos_x == M - 1)
		{
			cout << cnt;
			exit(0);
		}
		for(int i = 0; i < 4; i++)
		{
			int new_y = pos_y + dir_y[i];
			int new_x = pos_x + dir_x[i];
			if (new_y < 0 || new_y >= N || new_x < 0 || new_x >= M \
				|| map[new_y][new_x] == '0' || visited[new_y][new_x])
					continue;
			visited[pos_y + dir_y[i]][pos_x + dir_x[i]] = true;
			q.push(make_tuple(pos_y + dir_y[i], pos_x + dir_x[i], cnt + 1));
		}
	}
	return (0);
}