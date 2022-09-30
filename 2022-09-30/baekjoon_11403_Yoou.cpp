#include <iostream>
#include <cmath>
using namespace std;

int N;
int graph[101][101];

void floyd(void)
{
	for (int p = 0; p < N; p++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (graph[i][p] && graph[p][j])
					graph[i][j] = 1;
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// 1. init
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> graph[i][j];
	}
	// 2. floyd warshall
	floyd();
	// 3. print
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
			cout << graph[i][j] << ' ';
		cout << '\n';
	}
	return (0);
}