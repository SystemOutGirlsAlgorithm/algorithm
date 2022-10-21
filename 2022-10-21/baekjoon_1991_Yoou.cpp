// 백준 1991 트리 순회
#include <iostream>
#include <utility>
using namespace std;

int N;
pair<char, char> tree[26];

void input(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	char node, left, right;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> node >> left >> right;
		tree[node - 'A'].first = left;
		tree[node - 'A'].second = right;
	}
}

void preorder(char curr)
{
	if (curr != '.')
	{
		cout << curr;
		preorder(tree[curr - 'A'].first);
		preorder(tree[curr - 'A'].second);
	}
}

void inorder(char curr)
{
	if (curr != '.')
	{
		inorder(tree[curr - 'A'].first);
		cout << curr;
		inorder(tree[curr - 'A'].second);
	}
}

void postorder(char curr)
{
	if (curr != '.')
	{
		postorder(tree[curr - 'A'].first);
		postorder(tree[curr - 'A'].second);
		cout << curr;
	}
}

int main(void)
{
	input();
	preorder('A');
	cout << endl;
	inorder('A');
	cout << endl;
	postorder('A');
	return (0);
}