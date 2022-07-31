#include <iostream>
using namespace std;

int main()
{
	int dice_1, dice_2, dice_3;
	int max;

	cin >> dice_1;
	cin >> dice_2;
	cin >> dice_3;
	if (dice_1 > 0 && dice_2 > 0 && dice_3 > 0 && dice_1 < 7 && dice_2 < 7 &&  dice_3 < 7) {

		if ((dice_1 == dice_2) && (dice_2 == dice_3) && (dice_3 == dice_1))
		{
			cout << 10000 + (dice_1 * 1000); //1번조건
		}
		else if ((dice_1 == dice_2) && (dice_2 != dice_3)) //2번 조건
		{
			cout << 1000 + (dice_1 * 100);
		}
		else if ((dice_2 == dice_3) && (dice_3 != dice_1))
		{
			cout << 1000 + (dice_2 * 100);
		}
		else if ((dice_3 == dice_1) && (dice_1 != dice_2))
		{
			cout << 1000 + (dice_3 * 100);
		}
		else if ((dice_1 != dice_2) && (dice_2 != dice_3) & (dice_3 != dice_1)) //3번조건
		{
			if (dice_1 > dice_2 && dice_1 > dice_3)
			{
				max = dice_1;
				cout << max * 100;
			}
			else if (dice_2 > dice_3 && dice_2 > dice_1)
			{
				max = dice_2;
				cout << max * 100;
			}
			else if (dice_3 > dice_1 && dice_3 > dice_2)
			{
				max = dice_3;
				cout << max * 100;
			}
		}
		}
	else {
		cout << "error..." << endl;
	}
	return 0;
}