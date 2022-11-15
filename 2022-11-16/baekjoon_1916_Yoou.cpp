// 백준 1916 최소비용 구하기
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define INF 10000000000;
using namespace std;

int n, m;
int src, dest;
long shortest_dist[1001];
vector<pair<int, long> >connected[1001];

void input()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	int s, d;
	long w;
	for (int i = 0; i < m; i++)
	{
		cin >> s >> d >> w;
		connected[s].push_back(make_pair(d, w));
	}
	for(int i = 1; i <= n; i++)
		shortest_dist[i] = INF;
	cin >> src >> dest;
}

void dijkstra()
{
	priority_queue<pair<long, int>, vector<pair<long, int> >, greater<pair<long, int> > > pq; // first : dist, second : point
	long curr_dist, temp_dist;
	int curr_point, temp_point;
	pq.push(make_pair(0, src));
	shortest_dist[src] = 0;
	while (!pq.empty())
	{
		curr_dist = pq.top().first;
		curr_point = pq.top().second;
		pq.pop();
		if (shortest_dist[curr_point] < curr_dist)
			continue;
		for (int i = 0; i < connected[curr_point].size(); i++)
		{
			temp_point = connected[curr_point][i].first;
			temp_dist = connected[curr_point][i].second;
			if (shortest_dist[temp_point] > curr_dist + temp_dist)
			{
				shortest_dist[temp_point] = curr_dist + temp_dist;
				pq.push(make_pair(shortest_dist[temp_point], temp_point));
			}
		}
	}
	
}

int main()
{
	input();
	dijkstra();
	cout << shortest_dist[dest];
	return (0);
}
