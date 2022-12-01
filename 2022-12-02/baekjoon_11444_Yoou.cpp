// 백준 11444 피보나치 수 6
#include <iostream>
#define MOD 1000000007

using matrix22 = long long[2][2];

namespace matrix
{
	void multiply(matrix22 &A, matrix22 const &B)
	{
		long long a = A[0][0] * B[0][0] + A[0][1] * B[1][0];
		long long b = A[0][0] * B[0][1] + A[0][1] * B[1][1];
		long long c = A[1][0] * B[0][0] + A[1][1] * B[1][0];
		long long d = A[1][0] * B[0][1] + A[1][1] * B[1][1];

		A[0][0] = a % MOD;
		A[0][1] = b % MOD;
		A[1][0] = c % MOD;
		A[1][1] = d % MOD;
	}

	void power(matrix22 &A, long long n)
	{
		if(n == 0 || n == 1)
			return;
		matrix::power(A, n / 2);
		matrix::multiply(A, A);
		if (n % 2 != 0)
			matrix::multiply(A, {{1, 1}, {1, 0}});
	}
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	long long n;
	std::cin >> n;
	matrix22 tmp = {{1, 1}, {1, 0}};
	long long ans;
	if (n == 0)
		ans = 0;
	else
	{
		matrix::power(tmp, n - 1);
		ans = tmp[0][0];
	}
	std::cout << ans;
	return(0);
}