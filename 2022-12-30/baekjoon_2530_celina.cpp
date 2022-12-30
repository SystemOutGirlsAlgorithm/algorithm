#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {

	int a, b, c, d, h, m, s;
	scanf("%d %d %d %d", &a, &b, &c, &d);

	c += d;
	if (c >= 60) {
		b += (c / 60);
		c %=60;
		if (b >= 60) {
			a += (b / 60);
			b %= 60;
			if (a >= 24) {
				a = a % 24;
			}
		}
	}
	printf("%d %d %d", a, b, c);
	
	return 0;
}