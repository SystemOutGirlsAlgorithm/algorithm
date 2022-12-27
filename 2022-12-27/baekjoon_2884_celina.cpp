#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main() {

	int h, m;
	scanf("%d %d", &h, &m);

	if (m < 45) {
		h--;
		m = 60 - (45 - m);
		if (h < 0) {
			h = 23;
		}
		printf("%d %d", h, m);
	}
	else { //11½Ã 46ºÐ 
		printf("%d %d", h, m - 45);
	}

	return 0;
}


