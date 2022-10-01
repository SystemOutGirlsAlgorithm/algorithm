#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int	M, N, H;
int target = 0;
bool box[101][101][101];
queue <tuple<int, int, int> >tomatoes;	// z, y, x;
int dir_z[6] = {1, -1, 0, 0, 0, 0};
int dir_y[6] = {0, 0, 0, 0, 1, -1};
int dir_x[6] = {0, 0, -1, 1, 0, 0};

void init(void)
{
	int temp;

	cin >> M >> N >> H;
	for(int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				cin >> temp;
				if (temp == 1)
				{
					box[i][j][k] = true;
					tomatoes.push(make_tuple(i, j, k));
				}
				else if (temp == 0)
				{
					box[i][j][k] = false;
					target++;
				}
				else
					box[i][j][k] = true;
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int answer = 0;
	int cnt;
	int z, y, x, new_z, new_y, new_x;

	init();
	while (!tomatoes.empty())
	{
		if (target == 0)
			break;
		cnt = tomatoes.size();
		answer++;
		for(int i = 0; i < cnt; i++)
		{
			z = get<0>(tomatoes.front());
			y = get<1>(tomatoes.front());
			x = get<2>(tomatoes.front());
			tomatoes.pop();
			for(int k = 0; k < 6; k++)
			{
				new_z = z + dir_z[k];
				new_y = y + dir_y[k];
				new_x = x + dir_x[k];
				if (new_z < 0 || new_z >= H || new_y < 0 || new_y >= N || new_x < 0 || new_x >= M)
					continue;
				if (box[new_z][new_y][new_x])
					continue;
				target--;
				box[new_z][new_y][new_x] = true;
				tomatoes.push(make_tuple(new_z, new_y, new_x));
			}
		}
	}
	if (target != 0)
		cout << -1;
	else
		cout << answer;
	return (0);
}