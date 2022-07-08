#include<iostream>
using namespace std;

int main()
{
	int num[42] = { };

	int v;
	for (int i = 0; i < 10; i++)
	{
		cin >> v;
		num[v % 42]++;
	}
	int result = 0;

	for (int v : num) {
		if (v > 0) {
			result++;
		}
	}
	cout << result;

	return 0;
	
}

