// 백준 12852 1로 만들기 2
#include <iostream>
#include <cstring>
using namespace std;

int dp[1000001];
int before[1000001];
int n;

void solve()
{
	dp[1] = 0;
	before[1] = 0;
	for(int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + 1;
		before[i] = i - 1;

		if (i % 3 == 0)
		{
			if (dp[i] > dp[i / 3] + 1)
			{
				dp[i] = dp[i / 3] + 1;
				before[i] = i / 3;
			}
		}

		if (i % 2 == 0)
		{
			if (dp[i] > dp[i / 2] + 1)
			{
				dp[i] = dp[i / 2] + 1;
				before[i] = i / 2;
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	solve();
	cout << dp[n] << '\n';
	while(n != 0)
	{
		cout << n << ' ';
		n = before[n];
	}

	return (0);
}