#include <iostream>
#include <cmath>
using namespace std;

int N, r, c;
int answer = 0;

void divide_conquer(int size, int col, int row)
{
	if (size <= 0)
		return;
	if (col == c && row == r)
	{
		cout << answer;
		exit (0);
	}
	if (r >= row + size || c >= col + size)
		answer += size * size;
	else
	{
		divide_conquer(size / 2, col, row);	// 왼쪽 위
		divide_conquer(size / 2, col + size / 2, row);	// 오른쪽 위
		divide_conquer(size / 2, col, row + size / 2);	// 왼쪽 아래
		divide_conquer(size / 2, col + size / 2, row + size / 2);	// 오른쪽 아래
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> r >> c;
	divide_conquer(pow(2, N), 0, 0);
	return (0);
}