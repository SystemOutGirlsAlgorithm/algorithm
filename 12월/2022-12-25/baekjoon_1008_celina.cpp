#include <iostream>
using namespace std;

int main()
{
	double a, b;
	cin >> a;
	cin >> b;

	cout << fixed;
	cout.precision(9);
	cout << a / b;

	return 0;
}