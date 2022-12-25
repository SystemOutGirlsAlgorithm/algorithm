#include <iostream>
using namespace std;

int main()
{
	int L, P;
	cin >> L >> P;

	int a[5];
	for (int i = 0; i < 5; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < 5; i++) {
		if (L * P == a[i]) {
			cout << 0 << " ";
		}
		else {
			cout << a[i] - (L * P) << " ";
		}
	}

	return 0;
}