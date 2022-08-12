#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
	fastio;
	vector<int> v1(50);
	int num = 0;
	int search;
	int result = 0;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> v1[i];
	}
	cin >> search;
	for (int i = 0; i < num; i++)
	{
		if (v1[i] == search)
		{
			result++;
		}
	}
	cout << result;

}