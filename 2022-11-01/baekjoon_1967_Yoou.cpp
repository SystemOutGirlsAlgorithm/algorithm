// 백준 1967 트리의 지름
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;

int n, p, c, w;
int ans = 0;
vector<pair<int, int> > adj_list[10001];	// node, weight
bool visited[10001][10001];

void dfs(int start, int curr, int total_weight)
{
	int node, node_weight;
	visited[start][curr] = true;
	ans = max(ans, total_weight);
	for(int i = 0; i < adj_list[curr].size(); i++)
	{
		node = adj_list[curr][i].first;
		node_weight = adj_list[curr][i].second;
		if (!visited[start][node])
			dfs(start, node, total_weight + node_weight);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 0; i < n - 1; i++)
	{
		cin >> p >> c >> w;
		adj_list[p].push_back(make_pair(c, w));
		adj_list[c].push_back(make_pair(p, w));
	}
	memset(visited, false, sizeof(visited));
	for(int i = 1; i <= n; i++)
		dfs(i, i, 0);
	cout << ans;
	return (0);
}