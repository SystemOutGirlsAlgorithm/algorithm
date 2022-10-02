#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;

int N;
bool visited[100][100];
string picture[100];
int dir_y[4] = {-1, 0, 1, 0};
int dir_x[4] = {0, 1, 0, -1};
queue<tuple<int, int, char> > q;

int cnt_partition(void)
{
	int ret = 0;
	int y, x, new_y, new_x;
	char color;
	memset(visited, false, sizeof(visited));
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(visited[i][j])
				continue;
			q.push(make_tuple(i, j, picture[i][j]));
			visited[i][j] = true;
			while (!q.empty())
			{
				y = get<0>(q.front());
				x = get<1>(q.front());
				color = get<2>(q.front());
				q.pop();
				for(int k = 0; k < 4; k++)
				{
					new_y = y + dir_y[k];
					new_x = x + dir_x[k];
					if (new_y < 0 || new_y >= N \
						|| new_x < 0 || new_x >= N \
						|| visited[new_y][new_x] || picture[new_y][new_x] != color)
						continue;
					q.push(make_tuple(new_y, new_x, color));
					visited[new_y][new_x] = true;
				}
			}
			ret++;
		}
	}
	return (ret);
}

void R_to_G(void)
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if (picture[i][j] == 'R')
				picture[i][j] = 'G';
		}
	}
}

int deutan(void)
{
	R_to_G();
	return(cnt_partition());
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> picture[i];
	cout << cnt_partition() << ' ' << deutan();
	return (0);
}