#include <iostream>
#include <string>
using namespace std;

int N, M;
string S;
string P = "";

/* ======== *
 *   50점
 * ======== */

// int main(void)
// {
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	cout.tie(0);

// 	cin >> N;
// 	cin >> M;
// 	cin >> S;
// 	// make p
// 	for(int i = 0; i < 2 * N + 1; i++)
// 	{
// 		if (i % 2 == 0)
// 			P.push_back('I');
// 		else
// 			P.push_back('O');
// 	}
// 	int ans = 0;
// 	int temp = S.find(P, 0);
// 	while (temp != string::npos)
// 	{
// 		ans++;
// 		temp = S.find(P, temp + 2);
// 	}
// 	cout << ans;
// 	return (0);
// }

/* ======== *
 *   100점
 * ======== */

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	cin >> M;
	cin >> S;
	// make p
	for(int i = 0; i < 2 * N + 1; i++)
	{
		if (i % 2 == 0)
			P.push_back('I');
		else
			P.push_back('O');
	}
	int ans = 0;
	int p_len = 2 * N + 1;
	int idx = 0;
	int temp;
	while (idx < M)
	{
		while (idx < M && S[idx] != 'I')
			idx++;
		if (idx >= M)
			break;
		idx = S.find(P, idx);
		if (idx == string::npos)
			break;
		temp = 0;
		ans++;
		while (idx + p_len + temp < M)
		{
			if (temp % 2 != 0)
			{
				if (S[idx + p_len + temp] == 'I')
					ans++;
				else
					break;
			}
			else if (S[idx + p_len + temp] != 'O')
				break;
			temp++;
		}
		idx = idx + p_len + temp;
	}
	cout << ans;
	return (0);
}