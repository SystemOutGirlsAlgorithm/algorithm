#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int i, j, k ;
	for (i = 0; i < n; i++)
	{
		for (j = 0;j < (n - 1) - i;j++)
		{
			cout << " ";
		}

		for (j = 0;j < 1 + i;j++)
		{
			cout << "*";
		}
		
		cout << "\n";
	}

}
