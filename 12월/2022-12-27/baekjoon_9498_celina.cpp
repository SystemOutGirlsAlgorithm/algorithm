#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main() {

	int num;
	scanf("%d", &num);

	if (num >= 90 && num <= 100) {
		printf("A");
	}
	else if (num >= 80 && num < 90) {
		printf("B");
	}
	else if (num >= 70 && num < 80) {
		printf("C");
	}
	else if (num >= 60 && num < 70) {
		printf("D");
	}
	else {
		printf("F");
	}

	return 0;
}

