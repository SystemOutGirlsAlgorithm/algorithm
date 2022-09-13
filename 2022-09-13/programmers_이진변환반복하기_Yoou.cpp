#include <string>
#include <vector>

using namespace std;

string to_binary(int num)
{
    string ret = "";
    while (num != 0)
    {
        if (num % 2 == 0)
            ret.push_back('0');
        else
            ret.push_back('1');
        num /= 2;
    }
    return (ret);
}

vector<int> solution(string s) {
    vector<int> answer;
    int conversion_cnt = 0;
    int remove_cnt = 0;
    int temp_length;
    
    while (s != "1")
    {
        conversion_cnt++;
        temp_length = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if (s[i] == '0')
                remove_cnt++;
            else
                temp_length++;
        }
        s = to_binary(temp_length);
    }
    answer.push_back(conversion_cnt);
    answer.push_back(remove_cnt);
    return answer;
}