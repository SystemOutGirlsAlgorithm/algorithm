#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
bool visited[21];
vector<int> arr;
vector<int> print;

void pick(int cnt)
{
	if (cnt == M)
	{
		for(int i = 0; i < print.size(); i++)
			cout << print[i] << ' ';
		cout << "\n";
		return;
	}
	for(int i = 0; i < N; i++)
	{
		if (visited[i])
			continue;
		visited[i] = true;
		print.push_back(arr[i]);
		pick(cnt + 1);
		print.pop_back();
		visited[i] = false;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for(int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());
	memset(visited, false, sizeof(visited));
	pick(0);
	return (0);
}