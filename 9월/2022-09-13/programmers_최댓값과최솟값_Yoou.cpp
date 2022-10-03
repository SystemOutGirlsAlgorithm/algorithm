#include <string>
#include <vector>
#include <climits>

using namespace std;

string solution(string s) {
    string answer = "";
    int i = 0;
    int pos = 0;
    int ans_max = INT_MIN;
    int ans_min = INT_MAX;
    int num;
    while (i < s.length())
    {
        pos = i;
        while (i < s.length() && s[i] != ' ')
            i++;
        num = stoi(s.substr(pos, i - pos));
        if (num > ans_max)
            ans_max = num;
        if (num < ans_min)
            ans_min = num;
        i++;
    }
    answer += to_string(ans_min);
    answer += " ";
    answer += to_string(ans_max);
    return answer;
}