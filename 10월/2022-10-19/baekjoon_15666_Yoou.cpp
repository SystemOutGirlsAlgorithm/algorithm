#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <sstream>
using namespace std;

int N, M;
string str;
vector<int> arr;

struct Compare{
    bool operator() (const string &a, const string &b) const
    {
        stringstream sa, sb;
        sa.str(a);
        sb.str(b);
        int na, nb;
        while (sa >> na && sb >> nb)
        {
            if (na != nb)
                break;
        }
        return (na < nb);
    }
};

set<string, Compare> answer;

void input(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int temp;
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        cin >> temp;
        arr.push_back(temp);
    }
}

void str_push_back(string num)
{
	for(int i = 0; i < num.length(); i++)
		str.push_back(num[i]);
	str.push_back(' ');
}

void str_pop_back(string num)
{
	str.pop_back();
	for(int i = 0; i < num.length(); i++)
		str.pop_back();
}

void pick(int cnt, int curr_idx)
{
	if (cnt == M)
	{
		answer.insert(str);
        return;
	}
	for(int i = curr_idx; i < N; i++)
	{
		str_push_back(to_string(arr[i]));
		pick(cnt + 1, i);
		str_pop_back(to_string(arr[i]));
	}
}

void print_all(void)
{
    auto iter = answer.begin();
    while (iter != answer.end())
    {
        cout << *iter << '\n';
        iter++;
    }
}

int main(void)
{
    input();
    sort(arr.begin(), arr.end());
    pick(0, 0);
    print_all();
    return (0);
}