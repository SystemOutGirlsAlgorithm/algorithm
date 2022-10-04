#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <utility>
using namespace std;

int d(int num)
{
	num *= 2;
	if (num > 9999)
		num %= 10000;
	return (num);
}

int s(int num)
{
	if(num == 0)
		return 9999;
	else
		return (num - 1);
}

int l(int num)
{
	// cout << "Num : " << num << " | ";
	int temp = num / 1000;
	num %= 1000;
	num = num * 10 + temp;
	// cout << "L : " << num << "\n";
	return (num);
}

int r(int num)
{
	// cout << "Num : " << num << " | ";
	int temp = num % 10;
	num /= 10;
	num += temp * 1000;
	// cout << "R : " << num << "\n";
	return (num);
}

void DSLR(int A, int B)
{
	queue<pair<int, string> > q;
	bool visited[10001];
	int num, temp;
	string str;
	memset(visited, false, sizeof(visited));
	q.push(make_pair(A, ""));
	visited[A] = true;
	while (!q.empty())
	{
		num = q.front().first;
		str = q.front().second;
		q.pop();
		if (num == B)
		{
			cout << str << "\n";
			return ;
		}
		temp = d(num);
		if (!visited[temp])
		{
			visited[temp] = true;
			q.push(make_pair(temp, str + "D"));
		}
		temp = s(num);
		if (!visited[temp])
		{
			visited[temp] = true;
			q.push(make_pair(temp, str + "S"));
		}temp = l(num);
		if (!visited[temp])
		{
			visited[temp] = true;
			q.push(make_pair(temp, str + "L"));
		}temp = r(num);
		if (!visited[temp])
		{
			visited[temp] = true;
			q.push(make_pair(temp, str + "R"));
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T, A, B;
	cin >> T;
	for(int i = 0; i < T; i++)
	{
		cin >> A >> B;
		DSLR(A, B);
	}
	return (0);
}