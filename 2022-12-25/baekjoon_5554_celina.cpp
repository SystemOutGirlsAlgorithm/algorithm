#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;

	cout << (a + b + c + d) / 60 << endl;
	cout << (a + b + c + d) % 60;

	return 0;
}