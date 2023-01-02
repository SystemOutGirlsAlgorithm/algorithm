#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {

	int num[5];
	int n;
	int car = 0;
	scanf("%d", &n);
	for (int i = 0; i < 5; i++) {
		scanf("%d", &num[i]);
	}
	for (int i = 0; i < 5; i++) {
		if (num[i] == n) {
			car++;
		}
	}
	printf("%d", car);

	return 0;
}

