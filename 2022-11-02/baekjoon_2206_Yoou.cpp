// 백준 2206 벽 부수고 이동하기
#include <iostream>
#include <queue>
#include <utility>
#include <tuple>
#include <cstring>
using namespace std;

int n, m;
char map[1001][1001];
bool visited[2][1001][1001];
queue<tuple<pair<int, int>, int, bool> > q;	// (curr_pos(pair), path length, wall broken)

void input(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
			cin >> map[i];
	memset(visited, false, sizeof(visited));
}

/*
* 확인해야 하는 것 현재 방문한 지점을 가는 데 벽을 부순 적이 있는지를 확인해줘야 함.
* 전역변수로 체크하는 것은 불가능하다./
*/

int bfs(void)
{
	int y, x, length, new_y, new_x;
	bool wall_broken;
	int dir_y[4] = {-1, 0, 1, 0};
	int dir_x[4] = {0, 1, 0, -1};
	while (!q.empty())
	{
		y = get<0>(q.front()).first;
		x = get<0>(q.front()).second;
		length = get<1>(q.front());
		wall_broken = get<2>(q.front());
		q.pop();
		if (y == n - 1 && x == m - 1)
			return (length);
		for(int i = 0; i < 4; i++)
		{
			new_y = y + dir_y[i];
			new_x = x + dir_x[i];
			if (new_y < 0 || new_x < 0 || new_y >= n || new_x >= m)
				continue;
			if (visited[wall_broken][new_y][new_x])
				continue;
			if (map[new_y][new_x] == '1')
			{
				if (wall_broken)
					continue;
				visited[wall_broken][new_y][new_x] = true;
				//cout << "* [" << i << "] new_y : " << new_y << "\tnew_x : " << new_x << "\t" << wall_broken << "\n";
				q.push(make_tuple(make_pair(new_y, new_x), length + 1, true));
			}
			else
			{
				visited[wall_broken][new_y][new_x] = true;
				//cout << "@ [" << i << "] new_y : " << new_y << "\tnew_x : " << new_x << "\t" << wall_broken << "\n";
				q.push(make_tuple(make_pair(new_y, new_x), length + 1, wall_broken));
			}
				
		}
	}
	return (-1);
}

int main(void)
{
	input();
	q.push(make_tuple(make_pair(0, 0), 1, false));
	visited[0][0][0] = true;
	cout << bfs();
}