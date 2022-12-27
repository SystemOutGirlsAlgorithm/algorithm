#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main() {

	int B = 0;
	int D = 0;
	int b, d;
	for (int i = 0; i < 3; i++) {
		scanf("%d", &b);
		if (B == 0) {
			B = b; //처음입력할때 
		}
		if (b < B) {
			B = b; //B에값있는데b가더작으면그게B가됨
		}
	}
	for (int i = 0; i < 2; i++) {
		scanf("%d", &d);
		if (D == 0) {
			D = d;
		}
		if (d < D) {
			D = d;
		}
	}
	printf("%d", B + D - 50);

	return 0;
}



