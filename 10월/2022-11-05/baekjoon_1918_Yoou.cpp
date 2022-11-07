// 백준 1918 후위표기식
#include <iostream>
#include <string>
#include <stack>
using namespace std;

string input;

int priority(char c)
{
	if (c == '(')
		return (0);
	if (c == '+' || c == '-')
		return (1);
	if (c == '*' || c == '/')
		return (2);
	return (3);
}

bool is_operator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	else
		return (false);
}

void convert_postfix()
{
	stack<char> s;
	for(int i = 0; i < input.length(); i++)
	{
		if (input[i] == '(')
			s.push(input[i]);
		else if (input[i] == ')')
		{
			while (s.top() != '(')
			{
				cout << s.top();
				s.pop();
			}
			s.pop();
		}
		else if(is_operator(input[i]))
		{
			while (!s.empty() && priority(s.top()) >= priority(input[i]))
			{
				cout << s.top();
				s.pop();
			}
			s.push(input[i]);
		}
		else
			cout << input[i];
	}
	while(!s.empty())
	{
		cout << s.top();
		s.pop();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> input;
	convert_postfix();
	return(0);
}