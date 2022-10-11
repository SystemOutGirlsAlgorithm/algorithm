#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
string memo[101][101];

string str_num_add(string a, string b)	// a + b
{
	int temp = 0;
	string ret;
	while (!a.empty() || !b.empty() || temp != 0)
	{
		if (!a.empty())
		{
			temp += a.back() - '0';
			a.pop_back();
		}
		if (!b.empty())
		{
			temp += b.back() - '0';
			b.pop_back();
		}
		ret.push_back((temp % 10) + '0');
		temp /= 10;
	}
	reverse(ret.begin(), ret.end());
	return (ret);
}

string combination(int a, int b) // a C b
{
	if (a == b || b == 0)
		return ("1");
	if (memo[a][b] != "")
		return (memo[a][b]);
	memo[a][b] = str_num_add(combination(a - 1, b - 1), combination(a - 1, b));
	return (memo[a][b]);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	cout << combination(n, m);
	return (0);
}