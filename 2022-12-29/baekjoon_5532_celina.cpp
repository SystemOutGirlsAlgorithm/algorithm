#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {

	int l, a, b, c, d;
	int n = 0;
	scanf("%d %d %d %d %d", &l, &a, &b, &c, &d);

	if (a % c == 0 && b % d == 0) {
		if (a / c > b / d) {
			n = a / c;
		}
		else {
			n = b / d;
		}
		printf("%d", l - n);
	}
	else if (a % c == 0 && b % d != 0) {
		if (a / c > b / d + 1) {
			n = a / c;
		}
		else {
			n = b / d + 1;
		}
		printf("%d", l - n);
	}
	else if (a % c != 0 && b % d == 0) {
		if (a / c + 1 > b / d) {
			n = a / c + 1;
		}
		else {
			n = b / d;
		}
		printf("%d", l - n);
	}
	else {
		if (a / c + 1 > b / d + 1) {
			n = a / c + 1;
		}
		else {
			n = b / d + 1;
		}
		printf("%d", l - n);
	}


	return 0;
}