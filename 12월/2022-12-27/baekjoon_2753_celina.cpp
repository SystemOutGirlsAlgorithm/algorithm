#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main() {

	int num;
	scanf("%d", &num);

	if (num % 4 == 0 && num % 100 != 0 || num % 400 == 0) {
		printf("1");
	}
	else {
		printf("0");
	}

	return 0;
}


