#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<int>num(5);
	int n;
	int sum = 0;

	for (int i = 0; i < num.size(); i++) {
		scanf("%d", &num[i]);
	}
	for (int i = 0; i < num.size(); i++) {
		if (num[i] < 40) {
			num[i] = 40;
		}
		sum += num[i];
	}

	printf("%d", sum / 5);


	return 0;
}

