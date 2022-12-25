#include <iostream>
#include<string>
using namespace std;

int main()
{
	char a[7]; //이 수의 최대 길이가 6글자라고 했기 때문에 크기를 7로 지정함 
	cin >> a; ;

	cout << strtol(a, nullptr, 16);

	return 0;
}