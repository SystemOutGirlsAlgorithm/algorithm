#include <iostream>
#include <queue>
#include <cstring>
#include <utility>
#include <climits>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int x, curr_cnt, N, K;
	int answer = INT_MAX;
	bool visited[100001];
	queue<pair<int, int> > q;
	memset(visited, 0, sizeof(visited));
	cin >> N >> K;
	q.push(make_pair(N, 0));

	while (!q.empty())
	{
		x = q.front().first;
		curr_cnt = q.front().second;
		if (x == K)
		{
			if (answer > curr_cnt)
				answer = curr_cnt;
			q.pop();
		}
		else
		{
			visited[x] = true;
			if (x + 1 <= 100000 && !visited[x + 1])
				q.push(make_pair(x + 1, curr_cnt + 1));
			if (x - 1 >= 0 && !visited[x - 1])
				q.push(make_pair(x - 1, curr_cnt + 1));
			if (2 * x <= 100000 && !visited[2 * x])
				q.push(make_pair(2 * x, curr_cnt + 1));
			q.pop();
		}
	}
	cout << answer;
	return (0);
}