// 백준 5639 이진 검색 트리
#include <iostream>
#include <vector>
using namespace std;

vector<int> preorder;
// 가장 앞 원소 : 루트, 앞쪽의 루트보다 작은 원소들의 그룹 : 왼쪽 하위 트리, 뒤쪽의 루트보다 큰 원소들의 그룹 : 오른쪽 하위 트리.
// 이 구조가 재귀적으로 반복된다.

void postorder(int start, int end)
{
	int root = preorder[start];
	if (start >= end)
		return;
	int i = start + 1;
	while (i < end && preorder[i] <= root)
		i++;
	postorder(start + 1, i);
	postorder(i, end);
	cout << root << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int num;
	cin >> num;
	
	while(!cin.fail())
	{
		preorder.push_back(num);
		cin >> num;
	}
	postorder(0, preorder.size());
	return (0);
}