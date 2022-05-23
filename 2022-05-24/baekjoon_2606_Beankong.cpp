#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 2606 바이러스
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int iComputerCount, iPairCount = 0;
	int counter = 0;

	cin >> iComputerCount >> iPairCount;

	vector<vector<int>> vecNetworks(iPairCount, vector<int>(2, 0));// row-PairCount, col-2 
	vector<int> vecVirus(iComputerCount, 0);

	for (int i = 0; i < iPairCount; ++i)
	{
		int a, b;
		cin >> a >> b;

		vecNetworks[i][0] = a;
		vecNetworks[i][1] = b;
	}
	
	// 1번 컴퓨터 바이러스
	queue<int> q;
	q.push(1);
	vecVirus[0] = 1;
	
	while (!q.empty())
	{
		int iCurCom = q.front();
		q.pop();

		// 연결되어 있고 아직 감염되지 않은 컴퓨터들을 q에 넣는다.
		for (int i = 0; i < iPairCount; ++i)
		{
			if (vecNetworks[i][0] == iCurCom && vecVirus[vecNetworks[i][1] - 1] != 1)
			{
				q.push(vecNetworks[i][1]);
				vecVirus[vecNetworks[i][1] - 1] = 1;
				counter++;
			}
			else if(vecNetworks[i][1] == iCurCom && vecVirus[vecNetworks[i][0] - 1] != 1) 
			{
				q.push(vecNetworks[i][0]);
				vecVirus[vecNetworks[i][0] - 1] = 1;
				counter++;
			}
		}

	}

	cout << counter;


	return 0;
}
