#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {

	int km;
	scanf("%d", &km);
	if (km % 5 == 0) {
		printf("%d", km / 5);
	}
	else {
		printf("%d", km / 5 + 1);
	}

	return 0;
}