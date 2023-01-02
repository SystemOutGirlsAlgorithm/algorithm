#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {

	int a, b, c, t,n;
	int A, B, C; //몇번 눌러야하는지 
	scanf("%d", &t);

	if (t % 10 != 0) {
		printf("-1");
	}
	else {
		if (t / 60 >= 5) {
			n = t / 60;
			A = n / 5;
			B = n % 5;
			C = (t % 60) / 10;
			printf("%d %d %d", A, B, C);
		}
		else {
			A = 0;
			B = t / 60;
			C = (t % 60) / 10;
			printf("%d %d %d", A, B, C);
		}

	}

	
	return 0;
}
/*
* 
* 5분 = 300초
* 1분 = 60초
*       10초
* T 나누기 60
* 100 나누기 60 = 몫 1 나머지 40  
* 200 나누기 60 = 몫 3 나머지 20
* 800 나누기 60 = 몫 13 나머지 20
* 몫이 5이상이되면 A를 써야함 
* ex 몫이 5, 23, 19면 >>t나누기60을 n이라고 하자
* 또다시 5로나워서 A,B를 구해야함
* 여기서 몫은 A, 나머지가 B가됨 
* 몫
* 13 나누기 5 = 몫 2 나머지 3
* 5 나누기 5 = 몫 1 나머지 0
 23 나누기 5 = 몫 4 나머지 3
 19 나누기 5 = 몫 3 나머지 4 
	
*/