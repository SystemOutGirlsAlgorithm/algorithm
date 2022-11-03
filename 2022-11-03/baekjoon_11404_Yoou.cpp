// 백준 11404 플로이드
#include <iostream>
#include <cstring>
#include <climits>
#define INF 10000000000
using namespace std;

int n, m;
long long shortest_path[101][101];

void init(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a, b, c;
	cin >> n >> m;
	memset(shortest_path, 0, sizeof(shortest_path));
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		if (shortest_path[a][b] == 0 || shortest_path[a][b] > c)
			shortest_path[a][b] = c;
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(shortest_path[i][j] != 0 || i == j)
				continue;
			else
				shortest_path[i][j] = INF;
		}
	}
}

void FWA()
{
	long long ret, temp;
	long long sum = LONG_MAX;
	for(int p = 1; p <= n; p++)
	{
		for(int a = 1; a <= n; a++)
		{
			for(int b = 1; b <= n; b++)
				shortest_path[a][b] = min(shortest_path[a][b], shortest_path[a][p] + shortest_path[p][b]);
		}
	}
}

void print_ans()
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if (shortest_path[i][j] == INF)
				cout << 0 << ' ';
			else
				cout << shortest_path[i][j] << ' ';
		}
		cout << "\n";
	}
}

int main(void)
{
	init();
	FWA();
	print_ans();
	return (0);
}