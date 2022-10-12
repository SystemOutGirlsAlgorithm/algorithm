/****************************
 * 2022 10 12
 * baekjoon 15657 N과 M (8)
 ****************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> arr;
vector<int> print;

void pick(int idx, int cnt)
{
	if (cnt == M)
	{
		for(int i = 0; i < print.size(); i++)
			cout << print[i] << ' ';
		cout << "\n";
		return;
	}
	for(int i = idx; i < N; i++)
	{
		print.push_back(arr[i]);
		pick(i, cnt + 1);
		print.pop_back();
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for(int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());
	pick(0, 0);
	return (0);
}