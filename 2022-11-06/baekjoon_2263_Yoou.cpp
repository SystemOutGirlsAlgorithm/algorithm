// 백준 2263 트리의 순회
#include <iostream>
#include <algorithm>
using namespace std;

/*
	* 인오더 : 중위순회 (왼쪽자식, 루트, 오른쪽자식)
	* 포스트오더 : 후위순회 (왼쪽자식, 오른쪽자식, 루트)
	* 프리오더 : 전위순회 (루트, 왼쪽자식, 오른쪽자식)
	* 인오더와 포스트오더가 주어지면, 프리오더를 구하라
*/

int n;
int inorder[100000];
int postorder[100000];

void make_pre_order(int postorder_start, int postorder_end, int inorder_start, int inorder_end)
{
	if (postorder_start > postorder_end || inorder_start > inorder_end)
		return;
	int root = postorder[postorder_end];
	cout << root << ' ';
	int root_idx = find(inorder, inorder + n, root) - inorder;
	int left = root_idx - inorder_start;
	// left
	make_pre_order(postorder_start, postorder_start + left - 1, inorder_start, root_idx - 1);
	// right
	make_pre_order(postorder_start + left, postorder_end - 1, root_idx + 1, inorder_end);
}

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> inorder[i];
	for(int i = 0; i < n; i++)
		cin >> postorder[i];
	// 후위순회의 시작, 끝, 중위순회의 시작, 끝
	make_pre_order(0, n - 1, 0, n - 1);
	return (0);
}