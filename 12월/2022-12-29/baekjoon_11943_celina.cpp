#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {

	int a, b, c, d;

	scanf("%d %d", &a, &b);
	scanf("%d %d", &c, &d);

	if (a + d < b + c) {
		printf("%d", a + d);
	}
	else {
		printf("%d", b + c);
	}

	return 0;
}