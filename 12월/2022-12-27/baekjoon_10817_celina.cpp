#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<int>num(3);
	int n;
	for (int i = 0; i < num.size(); i++) {
		scanf("%d", &num[i]);
	}
	for (int i = 0; i < num.size() - 1; i++) {
		for (int j = 0; j < num.size() - 1 - i; j++) {
			if (num[j] < num[j + 1]) {
				n = num[j];
				num[j] = num[j + 1];
				num[j + 1] = n;

			}
		}
	}
	printf("%d", num[1]);

	return 0;
}


