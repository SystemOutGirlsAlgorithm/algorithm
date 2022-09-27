#include <iostream>
using namespace std;

void make_quad_tree(int pos_y, int pos_x, int size);

int N;
string map[64];
string ret;

int	compress(int pos_y, int pos_x, int size)
{
	char start = map[pos_y][pos_x];
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			if (map[pos_y + i][pos_x + j] != start)
				return (-1);
		}
	}
	return (start - '0');
}

void divide_quad(int pos_y, int pos_x, int size)
{
	int temp = compress(pos_y, pos_x, size / 2);
	if (temp == -1)
		make_quad_tree(pos_y, pos_x, size / 2);
	else
		ret.push_back('0' + temp);
}

void make_quad_tree(int pos_y, int pos_x, int size)
{
	int temp;
	ret.push_back('(');
	// 1. 왼쪽 위
	divide_quad(pos_y, pos_x, size);
	// 2. 오른쪽 위
	divide_quad(pos_y, pos_x + (size / 2), size);
	// 3. 왼쪽 아래
	divide_quad(pos_y + (size / 2), pos_x, size);
	// 4. 오른쪽 아래
	divide_quad(pos_y + (size / 2), pos_x + (size / 2), size);
	ret.push_back(')');
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> map[i];
	ret = to_string(compress(0, 0, N));
	if (ret == "-1")
	{
		ret = "";
		make_quad_tree(0, 0, N);
	}
	cout << ret;
	return (0);
}