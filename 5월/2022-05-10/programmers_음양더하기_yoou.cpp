#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    int num, sign;
    for(int i = 0; i < absolutes.size(); i++)
    {
        num = absolutes[i];
        sign = signs[i];
        if (sign == false)
            num *= -1;
        answer += num;
    }
    return answer;
}