#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int ans = 0;
	int start;
	string str;
	queue<int> nums;
	queue<char> ops;

	cin >> str;
	int i = 0;
	int num;
	while (i < str.length())
	{
		start = i;
		while (i < str.length() && (str[i] != '-' && str[i] != '+'))
			i++;
		num = stoi(str.substr(start, i - start));
		nums.push(num);
		if (i < str.length() && (str[i] == '-' || str[i] == '+'))
			ops.push(str[i]);
		i++;
	}
	ans = nums.front();
	nums.pop();
	bool minus_flag = false;
	while (!nums.empty())
	{
		if (ops.front() == '+' && !minus_flag)
			ans += nums.front();
		else if (ops.front() == '+' && minus_flag)
			ans -= nums.front();
		else
		{
			minus_flag = true;
			ans -= nums.front();
		}
		nums.pop();
		ops.pop();
	}
	cout << ans;
	return (0);
}