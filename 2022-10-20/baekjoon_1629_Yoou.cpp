// 백준 1629 곱셈

#include <iostream>
using namespace std;

long long a, b, c;

long long func(int n)
{
	long long temp;
	if (n == 0)
		return (1);
	if (n == 1)
		return (a % c);
	temp = func(n / 2);
	if (n % 2 == 0)
		return (temp * temp % c);
	else
		return (temp * temp % c * a) % c;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> a >> b >> c;
	cout << func(b);
	return (0);
}