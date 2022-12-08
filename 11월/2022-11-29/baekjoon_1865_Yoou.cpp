// 백준 1865 웜홀
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

#define INF 10001

int TC, N, M, W;
int arr[501];
vector<pair<int, int> > connected[501];	// index : 시작지점, first : 도착지점, second : 가중치

void init_info(void)
{
	int S, E, T;
	cin >> N >> M >> W;
	for(int i = 0; i <= N; i++)
		connected[i].clear();
	// 도로 (양방향)
	for(int i = 0; i < M; i++)
	{
		cin >> S >> E >> T;
		connected[S].push_back(make_pair(E, T));
		connected[E].push_back(make_pair(S, T));
	}
	// 웜홀 (단방향)
	for(int i = 0; i < W; i++)
	{
		cin >> S >> E >> T;
		connected[S].push_back(make_pair(E, T * -1));
	}
	for(int i = 0; i <= N; i++)
		arr[i] = INF;
}

bool simulation()
{
	int to, cost;
	arr[1] = 0;
	// N회 반복 (N번째에 업데이트가 된다면 cycle이 있다는 것.)
	for(int i = 1; i <= N; i++)
	{
		for(int from = 1; from <= N; from++)
		{
			for(int j = 0; j < connected[from].size(); j++)
			{
				to = connected[from][j].first;
				cost = connected[from][j].second;
				if (arr[to] > arr[from] + cost)
				{
					arr[to] = arr[from] + cost;
					if (i == N)
						return (true);
				}
			}
		}
	}
	return (false);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> TC;
	for(int i = 0; i < TC; i++)
	{
		init_info();
		if (simulation())
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return (0);
}